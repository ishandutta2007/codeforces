// Never thought that purely geometrical skills like inversion
// will be ever useful to me in algorithmic contests :)!
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

ll nwd(ll a, ll b) {
  a = abs(a);
  b = abs(b);
  if (b == 0) {
    return a;
  }
  return nwd(b, a % b);
}

struct p {
  ll x, y, den;
  p (ll _x = 0, ll _y = 0, ll _den = 1) {
    ll gcd = nwd(_x, nwd(_y, _den));
    x = _x / gcd;
    y = _y / gcd;
    den = _den / gcd;
    /* int zminusuj = 0;
    if (x < 0 || (x == 0 && y < 0)) */ 
  }
};
p sum (p a, p b, int zn) {
  return p(a.x * b.den + zn * b.x * a.den, a.y * b.den + zn * b.y * a.den, a.den * b.den);
}
bool cmp(p a, p b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.den < b.den;
}
bool cmppair(pair<p, p> a, pair<p, p> b) {
  if (cmp(a.first, b.first) || cmp(b.first, a.first)) return cmp(a.first, b.first);
  return cmp(a.second, b.second);
}
const int N = 2005;
const int M = 1e9 + 7;
p pkt[N];
ll pot[N];
vector<pair<p, p> > sumy;
vector<int> pom;
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    swap(b, c);
    pkt[i] = p(a * c * d * d, b * c * c * d, a * a * d * d + b * b * c * c);
    /* debug(a)
    debug(b)
    debug(c)
    debug(d)
    debug(pkt[i].x)
    debug(pkt[i].y)
    debug(pkt[i].den) */
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      p incl = sum(pkt[i], pkt[j], -1);
      if (incl.x < 0 || (incl.x == 0 && incl.y < 0)) {
        incl.x *= -1;
        incl.y *= -1;
      }
      ll gcd = nwd(incl.x, incl.y);
      incl.x /= gcd;
      incl.y /= gcd;
      incl.den = 1;
      sumy.PB(MP(sum(pkt[i], pkt[j], 1), incl));
    }
  }
  sort(ALL(sumy), cmppair);
  
  pot[0] = 1;
  for (int i = 1; i < N; i++) {
    pot[i] = 2 * pot[i - 1] % M;
  }
  int act = 1;
  ll res = 0;
  int licz = 1;
  //debug(M);
  for (int i = 0; i < SZ(sumy); i++) {
    /* debug(sumy[i].x)
    debug(sumy[i].y)
    debug(sumy[i].den) */
    if (i == SZ(sumy) - 1 || cmp(sumy[i].first, sumy[i + 1].first)) {
      //res += (pot[act] + M - act - 1);
      //res %= M;
      ll il = 1;
      pom.PB(licz);
      for (int j = 0; j < SZ(pom); j++) {
        il *= (pom[j] + 1);
        il %= M;
      }
      res += M + il - act - 1;
      res %= M;
     // debug(act);
      act = 1;
      licz = 1;
      pom.clear();
      
    } else {
      if (cmp(sumy[i].second, sumy[i + 1].second)) {
        pom.PB(licz);
        licz = 1;
      } else {
        licz++;
      }
      act++;
    }
  }
  
  cout<<res<<endl;
  
  // nie zapomnij o ll
  return 0;
}