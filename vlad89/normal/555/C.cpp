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

struct node {
  int l, r, minx, miny;
  
  bool operator < (const node& o) const {
    return l < o.l;
  }
};

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  set<node> s;
  s.insert({1, n, 1, 1});
  REP (i, q) {
    int x, y;
    char dir;
    cin >> x >> y >> dir;
    auto it = s.lower_bound({x+1, x+1});
    if (it == s.begin()) {
      cout << 0 << endl;
      continue;
    }
    it--;
    if (it->l > x || it->r < x) {
      cout << 0 << endl;
      continue;
    }
    if (dir == 'L') {
      cout << (x - it->minx + 1) << endl;
      node f = *it;
      s.erase(it);
      if (x != f.l) s.insert({f.l, x-1, f.minx, y+1});
      if (x != f.r) s.insert({x+1, f.r, f.minx, f.miny});
    } else {
      cout << (y - it->miny + 1) << endl;
      node f = *it;
      s.erase(it);
      if (x != f.l) s.insert({f.l, x-1, f.minx, f.miny});
      if (x != f.r) s.insert({x+1, f.r, x+1, f.miny});
    }
  }
  return 0;
}