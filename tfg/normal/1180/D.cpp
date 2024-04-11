#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(false); cin.tie(0);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = (int)1e5+10;

int main(){

  BUFF;

  int n, m; cin >> n >> m;

  int x1=1, x2=n;
  int y1=1, y2=m;

  // vector<pii> mv;

  while( y1 < y2 ){

    while( x1 <= n and x2 >=1 ){
      cout << x1++ << " " << y1 << endl;
      // mv.pb({x1, y1});
      cout << x2-- << " " << y2 << endl;
      // mv.pb({x2, y2});
    }

    x1=1; x2=n;
    y1++; y2--;
  }

  int at=0, p1=1, p2=n;
  if( y1 == y2 ){
    while( at < n ){
      // mv.pb({(at%2==0 ? p1 : p2), y1});
      cout << (at%2==0 ? p1++ : p2--) << " " << y1 << endl;
      at++;
    }
  }

  // set<pii> st;
  //
  // for( int i=0; i<mv.size()-1; i++ ){
  //   cout << mv[i+1].f-mv[i].f << " " << mv[i+1].s-mv[i].s << endl;
  //   st.insert({mv[i+1].f-mv[i].f, mv[i+1].s-mv[i].s});
  // }
  //
  // cout << st.size() << endl;
  // assert(st.size() == (n*m)-1);

  return 0;
}