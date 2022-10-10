#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 300500;

int pv[ maxn ];
int h[ maxn ];
int maxpath[ maxn ];

int dsu_get( int i )
{
   return i == pv[ i ] ? i : pv[ i ] = dsu_get( pv[ i ] );
}

void dsu_unite( int i, int j )
{
   i = dsu_get( i );
   j = dsu_get( j );
   if( i == j )
      return;

   int res;
   if( h[ i ] == h[ j ] )
   {
      res = i;
      pv[ j ] = i;
      h[ i ]++;
   }
   else if( h[ i ] < h[ j ] )
   {
      res = j;
      pv[ i ] = j;
   }
   else
   {
      res = i;
      pv[ j ] = i;
   }
   int mx = max( maxpath[ i ], maxpath[ j ] );
   mx = max( mx, ( maxpath[ i ] + 1 ) / 2 + ( maxpath[ j ] + 1 ) / 2 + 1 );
   maxpath[ res ] = mx;
}

vector<int> g[ maxn ];
bool used[ maxn ][ 3 ];

pair<int, int> longest_from( int i, int tt )
{
   used[ i ][ tt ] = 1;
   int j, k = g[ i ].size();
   pair<int, int> res = make_pair( 0, i );
   for( j = 0; j < k; ++j )
      if( !used[ g[ i ][ j ]][ tt ] )
      {
         auto rec = longest_from( g[ i ][ j ], tt );
         if( res.first < rec.first + 1 )
         {
            res = rec;
            ++res.first;
         }
      }
   return res;
}

void unite( int i )
{
   used[ i ][ 2 ] = 1;
   int j, k = g[ i ].size();
   for( j = 0; j < k; ++j )
      if( !used[ g[ i ][ j ]][ 2 ] )
      {
         unite( g[ i ][ j ] );
         dsu_unite( i, g[ i ][ j ] );
      }
}

namespace
{
   void run()
   {
      int n, m, q;
      cin >> n >> m >> q;
      int i, a, b, j;
      for( i = 0; i < m; ++i )
      {
         cin >> a >> b;
         g[ a - 1 ].push_back( b - 1 );
         g[ b - 1 ].push_back( a - 1 );
      }

      for( i = 0; i < n; ++i )
      {
         pv[ i ] = i;
         h[ i ] = 0;
      }

      for( i = 0; i < n; ++i )
      {
         if( !used[ i ][ 1 ] )
         {
            auto p = longest_from( i, 0 );
            p = longest_from( p.second, 1 );
            unite( i );
            maxpath[ dsu_get( i ) ] = p.first;
         }
      }

      int t;
      for( i = 0; i < q; ++i )
      {
         cin >> t;
         if( t == 1 )
         {
            cin >> a;
            cout << maxpath[ dsu_get( a - 1 ) ] << endl;
         }
         else
         {
            cin >> a >> b;
            dsu_unite( a - 1, b - 1 );
         }
      }
   }
 
}
// c
int main() { run(); return 0; }