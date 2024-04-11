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

int w[555];
int a[1111];
bool used[555];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    REP (i, n) cin >> w[i];
    vi order;
    ll ans = 0;
    REP (i, m) {
      cin >> a[i];
      --a[i];
      if (!used[a[i]]) {
	used[a[i]] = true;
	order.pb(a[i]);
      }
      REP (j, sz (order)) {
	if (order[j] == a[i]) {
	  order.erase(order.begin() + j);
	  order.insert(order.begin(), a[i]);
	  break;
	}
	ans += w[order[j]];
      }
    }
    cout << ans << endl;
    return 0;
}