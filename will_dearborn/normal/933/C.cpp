#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

struct pt
{
	ld x, y;
	explicit pt() { }
	explicit pt(ld x, ld y): x(x), y(y) { }
};

inline bool operator< (const pt& a, const pt& b)
{
	if (abs(a.x - b.x) > EPS) return a.x < b.x;
	if (abs(a.y - b.y) > EPS) return a.y < b.y;
	return false;
}

inline pt operator- (const pt& a, const pt& b) { return pt(a.x - b.x, a.y - b.y); }
inline pt operator+ (const pt& a, const pt& b) { return pt(a.x + b.x, a.y + b.y); }
inline pt operator* (const pt& a, const ld& b) { return pt(a.x * b, a.y * b); }
inline pt operator/ (const pt& a, const ld& b) { return pt(a.x / b, a.y / b); }

inline bool operator== (const pt& a, const pt& b) { return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS; }

inline ld dist(const pt& a, const pt& b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
inline ld len(const pt& v) { return dist(v, pt(0, 0)); }

inline pt normal(const pt& v) { return len(v) < EPS ? v : v / len(v); }
inline pt normal(const pt& v, const ld& l) { return normal(v) * l; }

inline pt rotate(const pt& v, const ld& sina, const ld& cosa) { return pt(v.x * cosa - v.y * sina, v.x * sina + v.y * cosa); }

struct circle
{
	pt c;
	ld r;
};

inline vector<pt> intersect(const circle& a, const circle& b)
{
	if (a.c == b.c) return vector<pt> (abs(a.r - b.r) < EPS ? 3 : 0);
	
	ld d = dist(a.c, b.c);
	
	if (d - EPS > a.r + b.r) return vector<pt> ();
	if (d + min(a.r, b.r) + EPS < max(a.r, b.r)) return vector<pt> ();
	
	ld cosa = (sqr(a.r) + sqr(d) - sqr(b.r)) / (2 * a.r * d);
	cosa = max(ld(-1), min(ld(1), cosa));
	ld sina = sqrt(1 - sqr(cosa));
	
	pt v = normal(b.c - a.c, a.r);
	
	vector<pt> ans(2);
	ans[0] = a.c + rotate(v, sina, cosa);
	ans[1] = a.c + rotate(v, -sina, cosa);
	
	if (abs(sina) < EPS) ans.pop_back();
	
	return ans;
}

ll p2(ll x) {
  return x * x;
}

void add(pt cur, vector<pt>& x) {
  bool fail = 0;
  for (pt y : x) {
    if (dist(y, cur) < EPS) fail = 1;
  }
  if (!fail) x.push_back(cur);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 3>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }
  int add1 = 1;
  for (int i = 0; i < v.size(); ++i) {
    bool ok = 0;
    for (int j = 0; j < v.size(); ++j) if (i != j) {
      int d2 = p2(v[i][0] - v[j][0]) + p2(v[i][1] - v[j][1]);
      if (d2 <= p2(v[i][2] + v[j][2]) && d2 >= p2(v[i][2] - v[j][2])) {
        ok = 1;   
      }
    }
    if (!ok) {
      ++add1;
      v.erase(v.begin() + i);
      --i;
    }
  }
  int res = 0;
  if (!v.empty()) {
    vector<vector<pt>> x(v.size());
    vector<pt> all;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        circle a, b;
        a.r = v[i][2];
        b.r = v[j][2];
        a.c = pt(v[i][0], v[i][1]);
        b.c = pt(v[j][0], v[j][1]);
        vector<pt> res = intersect(a, b);
        for (pt cur : res) {
          add(cur, x[i]);
          add(cur, x[j]);
          add(cur, all);
        }
      }
    }
    res = 1;
    for (int i = 0; i < v.size(); ++i) res += x[i].size();
    res -= all.size();
  }
  cout << res + add1 << endl;
  return 0;
}