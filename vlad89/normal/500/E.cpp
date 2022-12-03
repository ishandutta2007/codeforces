#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

//D
string _str(const bool x) {ostringstream str; str << (x ? "true" : "false"); return str.str(); }
string _str(const int x) {ostringstream str; str << x; return str.str(); }
string _str(const long long x) {ostringstream str; str << x; return str.str(); }
string _str(const char x) {ostringstream str; str << "'" << x << "'"; return str.str(); }
string _str(const string x) {ostringstream str; str << '"' << x << '"'; return str.str(); }
string _str(const double x) {ostringstream str; str.precision(6); str.setf(ios::fixed); str << x; return str.str(); }
string _str(const pii x) {ostringstream str; str << "(" << x.first << ", " << x.second << ")"; return str.str(); }
string _str(const char* x) { return _str((string) x);}
template<class T> string _str(const vector<T> x) {ostringstream str; str << "["; for(int i = 0; i < x.size(); ++i) { if (i) str << ", "; str << _str(x[i]); } str << "] size " << x.size(); return str.str(); }
template<class T> string _str(const set<T> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << it; } str << "} size " << x.size(); return str.str(); }
template<class K, class V> string _str(const map<K, V> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << it.X << " -> " << it.Y; } str << "} size " << x.size(); return str.str(); }

#ifdef LocalHost
#define D(x) cout << #x" = " << _str(x) << endl;
#define D2(x1, x2) cout << #x1" = " << _str(x1) << " | " << #x2" = " << _str(x2) << endl;
#define D3(x1, x2, x3) cout << #x1" = " << _str(x1) << " | " << #x2" = " << _str(x2) << " | " << #x3" = " << _str(x3) << endl;
#define D4(x1, x2, x3, x4) cout << #x1" = " << _str(x1) << " | " << #x2" = " << _str(x2) << " | " << #x3" = " << _str(x3) << " | " << #x4" = " << _str(x4) << endl;
#else
#define D(x);
#define D2(x1, x2);
#define D3(x1, x2, x3);
#define D4(x1, x2, x3, x4);
#endif
//~D


const int N = 222222;
int n;
int pos[N], len[N];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    REP (i, n) {
      scanf("%d%d", &pos[i], &len[i]);
    }
    int m;
    scanf("%d", &m);
    vector<pair<pii, int> >a(m);
    vector<long long> ans(m);
    REP (i, m) {
      scanf("%d%d", &a[i].X.X, &a[i].X.Y);
      a[i].X.X--;
      a[i].X.Y--;
      a[i].Y = i;
    }
    sort(all(a));
    vector<pii> incr;
    vector<long long> sums;
    for (int i = n-1; i >= 0; --i) {
      int reach = pos[i] + len[i];
      while (sz(incr) && pos[i] + len[i] >= pos[incr.back().X]) {
	reach = max(reach, incr.back().Y);
	incr.pop_back();
	sums.pop_back();
      }
      if (sz(incr)) {
	sums.pb(sums.back() + pos[incr.back().X] - reach);
      } else {
	sums.pb(0);
      }
      incr.pb(pii(i, reach));
      // D(i);
      // D(incr);
      // D(sums);
      while (sz(a) && a.back().X.X == i) {
	int p = lower_bound(all(incr), make_pair(a.back().X.Y, -1u/2), greater<pii>())-incr.begin();
	if (sz(sums)) ans[a.back().Y] += sums.back();
	if (p < sz(sums)) ans[a.back().Y] -= sums[p];
	//	D2(a.back().X.Y, p);
	a.pop_back();
      }
    }
    REP (i, sz (ans)) {
      cout << ans[i] << endl;
    }
    cout << endl;
    return 0;
}