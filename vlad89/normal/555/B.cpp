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
typedef pair<ll, ll> pll;

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<ll> l(n), r(n);
  REP (i, n) {
    cin >> l[i] >> r[i];
  }
  vector<pair<pll, int>> a;
  REP (i, n-1) {
    a.pb(make_pair(pll(l[i+1] - r[i], r[i+1] - l[i]), i));
  }
  vector<pll> b(m);
  REP (i, m) {
    cin >> b[i].X;
    b[i].Y = i;
  }
  sort(all(a));
  sort(all(b));
  int pa = 0;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vector<int> ans(sz(a));
  bool yes = true;
  REP (i, sz(b)) {
    while (pa < sz(a) && a[pa].X.X <= b[i].X) {
      pq.push(pll(a[pa].X.Y, a[pa].Y));
      ++pa;
    }
    if (sz(pq)) {
      if (pq.top().X < b[i].X) {
	yes = false;
	break;
      }
      ans[pq.top().Y] = b[i].Y;
      pq.pop();
    }
  }
  if (sz(pq) || pa < sz(a)) yes = false;
  cout << (yes ? "Yes" : "No") << endl;
  if (yes) {
    REP (i, sz (ans)) {
      if (i) cout << ' ';
      cout << ans[i]+1;
    }
    cout << endl;
  }
  return 0;
}