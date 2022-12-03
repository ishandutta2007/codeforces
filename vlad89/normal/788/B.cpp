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

vector<vi> a;
vector<bool> has;
int cnt;

void dfs(int x) {
	has[x] = false;
	for (int y : a[x]) {
		++cnt;
		if (has[y]) {
			dfs(y);
		}
	}
}

ll cn2(ll x) {
	return x * (x - 1) / 2;
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	a.resize(n);
	has.resize(n);
	ll res = 0;
	ll loops = 0;
	REP(i, m) {
		int q, w;
		cin >> q >> w;
		--q, --w;
		has[q] = true;
		has[w] = true;
		if (q == w) 
			loops++; 
		else {
			a[w].pb(q);
			a[q].pb(w);
		}
	}
	REP (i, n)
		if (has[i]) {
			dfs(i);
			break;
		}
	bool bad = count(all(has), true);
	if (!bad) {
		REP(i, n)
			res += cn2(sz(a[i]));
		res += cn2(loops);
		res += loops * (m - loops);	
		cout << res << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}