#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#endif
#ifndef LOCAL
#define debug(x)
#define debugv(x)
#endif
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const int N = 42;
int que[N][N][N][N];
int sum_pref[N][N];
int tu[N][N][N][N];
int tab[N][N];
int sum_kol[N][N];
int pom[N][N][N][N];
char row[N];
int main()
{
  // nie zapomnij o ll
  //ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n, m, q;
  cin>>n>>m>>q;
  RE (i, n) {
    scanf("%s", row + 1);
    RE (j, m) {
      int a;
      a = int(row[j]) - int('0');
      //cout<<tab[i][j];
      tab[i][j] = a;
      sum_kol[i][j] = sum_kol[i - 1][j] + tab[i][j];
      sum_pref[i][j] = sum_pref[i - 1][j] + sum_pref[i][j - 1] - sum_pref[i - 1][j - 1] + a;
      RE (k, i) {
        RE (l, j) {
          //debug(tu[i][j][k][l]);
          if (sum_pref[i][j] + sum_pref[k - 1][l - 1] == sum_pref[i][l - 1] + sum_pref[k - 1][j]) {
            tu[i][j][k][l] = 1;;
            
          }
        }
      }
      
    }
    //cout<<endl;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = i; k >= 1; k--) {
        for (int l = j; l >= 1; l--) {
          pom[i][j][k][l] = pom[i][j][k + 1][l] + pom[i][j][k][l + 1] - pom[i][j][k + 1][l + 1];
          pom[i][j][k][l] += tu[i][j][k][l];
        }
      }
    }
  }
  
  
  
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = i; k <= n; k++) {
        for (int l = j; l <= m; l++) {
          que[i][j][k][l] = que[i][j][k - 1][l] + que[i][j][k][l - 1] - que[i][j][k - 1][l - 1] + pom[k][l][i][j];
        }
      }
    }
  }
  
  RE (i, q) {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<que[a][b][c][d]<<"\n";
  }
  /* 
  
  
  
  
  int sum
  RE (i1, n) {
    FOR (i2, i1, n) {
      RE (k, m) {
        RE (l, m) {
          dep[k][l] = 0;
        }
      }
      
      RE (j, m) {
        FOR (i3, i1, i2) {
          FOR (i4, i3, i2) {
            if (sum_kol[i3 - 1][j] == sum_kol[i4][j]) {
              dep[i3][i4]++;
            } else {
              dep[i3][i4] = 0;
            }
            
      
  
  
  */
  
  
  // nie zapomnij o ll
  return 0;
}