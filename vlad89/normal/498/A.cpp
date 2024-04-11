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

int sign(ll x) {
  return x < 0 ? -1 : 1;
}

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    int ans = 0;
    REP (i, n) {
      ll a, b, c;
      cin >> a >> b >> c;
      if (sign(x1 * a + y1 * b + c) != sign(x2 * a + y2 * b + c)) ++ans;
    }
    cout << ans << endl;
    return 0;
}