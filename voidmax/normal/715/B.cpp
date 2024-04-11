#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <long double, long double>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
//#define _CRT_DISABLE_PERFCRIT_LOCKS
using namespace std;

typedef long long base;
const base inf = 1e18;

base l;
int n, m;
int s, f;
vector <pair <int, int>> names;
vector <base> cost;
vector <int> arr;
vector <int> nums;
vector <int> edge[1001];
bool used[1001];
base dist[1001];

base min_dist() {
	For(i, 0, n) dist[i] = inf;
	For(i, 0, n) used[i] = false;
	dist[s] = 0;
	For(i, 0, n) {
		int v = -1;
		For(j, 0, n) {
			if (used[j]) continue;
			if (v == -1 || dist[v] > dist[j]) {
				v = j;
			}
		}
		if (v == f) return dist[v];
		for (int j: edge[v]) {
			int u = arr[j] ^ v;
			dist[u] = min(dist[u], dist[v] + cost[j]);
		}
		used[v] = true;
	}
	return inf;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin >> n >> m >> l >> s >> f;
	For(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.pb(a ^ b);
		cost.pb(c);
		if (c == 0) nums.pb(i);
		names.pb({a, b});
		edge[a].pb(i);
		edge[b].pb(i);
	}  
	for (int i: nums) cost[i] = 1;
	if (min_dist() > l) {
		cout << "NO" << endl;
		return 0;
	} 
	for (int i: nums) cost[i] = inf;
	if (min_dist() < l) {
		cout << "NO" << endl;
		return 0;
	}
	int L = 1, R = l + 1;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		for (int i: nums) cost[i] = M;
		if (min_dist() <= l) {
			L = M;
		} else {
			R = M;
		}
	}
	int ans = L;
	L = 0, R = nums.size();
	while (R - L > 1) {
		int M = (L + R) >> 1;
		For(i, 0, M) cost[nums[i]] = ans + 1;
		For(i, M, nums.size()) cost[nums[i]] = ans;
		if (min_dist() <= l) {
			L = M;
		} else {
			R = M;
		}
	}
	For(i, 0, L) cost[nums[i]] = ans + 1;
	For(i, L, nums.size()) cost[nums[i]] = ans;
	cout << "YES" << endl;
	For(i, 0, m) {
		cout << names[i].x << ' ' << names[i].y << ' ' << cost[i] << endl;
	}
}