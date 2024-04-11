#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }


const string FILENAME = "input";
typedef pair<int, int> point;
typedef long double base;

const int MAXN = 1 << 22;

int n, m;
int edge[22];
int dp[MAXN];
pair<int, int> way[MAXN];

int main() {
	srand(time(0));
   	ios::sync_with_stdio(0);
   	//read(FILENAME);
   	cin >> n >> m;
   	if (m == (n * (n - 1)) / 2) {
   		cout << 0 << endl << endl;
   		return 0;
   	}
   	for (int i = 0; i < m; ++i) {
   		int a, b;
   		cin >> a >> b;
   		--a, --b;
   		edge[a] |= (1 << b);
   		edge[b] |= (1 << a);
   	}
   	for (int i = 0; i < n; ++i) edge[i] |= (1 << i);
   	int mn = 1 << n;
   	for (int i = 0; i < mn; ++i) dp[i] = 1e9;
   	dp[0] = 0;
   	for (int i = 0; i < n; ++i) {
   		dp[edge[i]] = 1;
   		way[edge[i]] = {i, 0};
   	}
   	for (int i = 0; i < mn; ++i) {
   		if (dp[i] > n) continue;
   		for (int j = 0; j < n; ++j) {
   			if ((i >> j) & 1) {
	   			int q = i | edge[j];
	   			if (dp[q] > dp[i] + 1) {
	   				dp[q] = dp[i] + 1;
	   				way[q] = {j, i};
	   			}
	   		}
   		}
   	}
   	cout << dp[mn - 1] << endl; 
   	vector<int> ans;
   	int id = mn - 1;
   	while (dp[id] > 0) {
   		ans.pb(way[id].x + 1);
   		id = way[id].y;
   	}
   	reverse(ans.begin(), ans.end());
   	for (int i : ans) cout << i << ' ';
   	cout << endl;
}