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
#include <queue>

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

namespace debug {
  
template<class T> string _str(const T x) {ostringstream str; str << x; return str.str(); }
string _str(const bool x) {ostringstream str; str << (x ? "true" : "false"); return str.str(); }
string _str(const int x) {ostringstream str; str << x; return str.str(); }
string _str(const long long x) {ostringstream str; str << x; return str.str(); }
string _str(const char x) {ostringstream str; str << "'" << x << "'"; return str.str(); }
string _str(const string x) {ostringstream str; str << '"' << x << '"'; return str.str(); }
string _str(const double x) {ostringstream str; str.precision(6); str.setf(ios::fixed); str << x; return str.str(); }
string _str(const char* x) { return _str((string) x);}

template<class K, class V> string _str(const pair<K, V> x);
template<class T> string _str(const vector<T> x);
template<class T> string _str(const set<T> x);
template<class K, class V> string _str(const map<K, V> x);

template<class K, class V> string _str(const pair<K, V> x) {ostringstream str; str << '(' << _str(x.first) << ", " << _str(x.second) << ')'; return str.str();}   
template<class T> string _str(const vector<T> x) {ostringstream str; str << "["; for(int i = 0; i < x.size(); ++i) { if (i) str << ", "; str << _str(x[i]); } str << "] size " << x.size(); return str.str(); }
template<class T> string _str(const set<T> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << _str(it); } str << "} size " << x.size(); return str.str(); }
template<class K, class V> string _str(const map<K, V> x) {ostringstream str; str << "{"; bool first = true; for(auto it: x) { if (!first) str << ", "; first = false; str << _str(it.X) << " -> " << _str(it.Y); } str << "} size " << x.size(); return str.str(); }

void _dvar(bool isfirst, vector<string>::iterator it) {}
template<typename TCur, typename... TArgs>
void _dvar(bool isfirst, vector<string>::iterator it, TCur cur, TArgs... x) {if (!isfirst) cerr << " | "; cerr << *it << " = " << _str(cur); _dvar(false, ++it, x...); }

template<typename... TArgs>
void _d(string arg_names, TArgs... args) {
  int open = 0;
  vector<string> names;
  string cur;
  char wait_for_quote = 0;
  for (char c: arg_names) {
    if (c == ',' && open == 0 && !wait_for_quote) {
      names.pb(cur);
      cur = "";
    } else {
      cur += c;
      if (wait_for_quote) {
	if (wait_for_quote == c)
	  wait_for_quote = 0;
      } else {
	if (c == '\'' || c == '"') wait_for_quote = c; else {
	  if (c == '(') open++; else if (c == ')') open--;
	}
      }
    }
  }
  if (sz(cur)) {
    names.pb(cur);
  }
  _dvar(true, names.begin(), args...);
  cout << endl;
}
	
#ifdef LocalHost
#define D(x...) _d(#x, x)
// Use it as C(__LINE__)
#define C(line, x...) cout << __FILE__ << ":" << line << " "; D(x)
#else
#define D(x);
#define C(x);
#endif
} // ~namespace debug
using namespace debug;

int x[200000], indx[200000];
pii p[200000];

template <class It>
It less_eq(It a, It b, int val) {
  return lower_bound(a, b, val+1) - 1;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  REP (i, n) {
    cin >> p[i].X;
    p[i].Y = i;
  }
  sort(p, p+n);
  REP (i, n) {
    x[i] = p[i].X;
    indx[p[i].Y] = i;
  }
  REP (i, m) {
    int cur, len;
    cin >> cur >> len;
    cur--;
    cur = indx[cur];
    while (1) {
      int next = less_eq(x, x + n, x[cur] + len) - x;
      int next_len = x[cur] + len - x[next];
      int next2 = lower_bound(x, x + n, x[next] - next_len) - x;
      int next2_len = x[next2] - (x[next] - next_len);
      //      D(cur, len, next, next_len, next2, next2_len);
      if (cur == next && next == next2) {
	cout << p[cur].Y+1 << endl;
	break;
      }
      if (next2 == cur) {
	len %= 2 * (x[next] - x[cur]);
      } else {
	cur = next2;
	len = next2_len;
      }
    }
  }
  return 0;
}