#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

const int mod = 1e9 + 7;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

const int N = (1 << 21) + 5;
int a[N];
int height[N];
ll ans = 0;
int h, g, n;

vector<int> qq;

int get(int u) {
	// cout << u << endl;
	if(a[u] == 0){
		return height[u] - 1;
	}
	int u1 = u << 1, u2 = u1 | 1;
	if(a[u1] > a[u2]) return get(u1);
	else return get(u2);
}

void remove(int u) {
	int u1 = u << 1, u2 = u1 | 1;
	if(!a[u]) return;
	if(a[u1] > a[u2]) { a[u] = a[u1]; remove(u1); }
	else { a[u] = a[u2]; remove(u2); }
}

void dfs(int u) {
	if(a[u] == 0) return;
	if(height[u] > g) return;
	while(1) {
		// cout << "U : " << u << endl;
		int hh = get(u);
		// cout << "H: " << hh << endl;
		if(hh <= g) break;
		qq.push_back(u);
		remove(u);
		// for(int i = 1; i <= n; i++) {
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
	}
	ans += a[u];
	dfs(u << 1);
	dfs(u << 1 | 1);
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	height[1] = 1;
	for(int i = 2; i < N; i++) {
		height[i] = height[i >> 1] + 1;
	}
	while(t--) {
		qq.clear();
		ans = 0;
		cin >> h >> g;
		n = (1 << h) - 1;
for (int i = 0; i < 2 * n + 5; i++) a[i] = 0;
qq.clear();

		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = n + 1; i <= 2 * n; i++) {
			a[i] = 0;
		}
		dfs(1);
		cout << ans << endl;
		for(int x : qq)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}