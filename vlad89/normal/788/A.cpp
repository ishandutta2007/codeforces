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

int a[123456];

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	REP(i, n) {
		cin >> a[i];
		if (i)
			a[i - 1] = abs(a[i] - a[i - 1]);
	}
	n--;
	ll mi = 0, ma = 0;
	ll res = 0;
	for (int i = n - 1; i >= 0; --i) {
		ll tmi = mi;
		mi = a[i] - max(ma, 0LL);
		ma = a[i] - min(tmi, 0LL);
		res = max(res, ma);
	}
	cout << res << endl;
	return 0;
}