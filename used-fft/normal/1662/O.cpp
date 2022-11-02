#include <bits/stdc++.h>
using namespace std;
#define int long long

const int DEG = 360, RLIM = 21, Z = DEG * (RLIM + 1);

bool gInv[Z][4], vis[Z], ok;
// {outwards, inwards, clockwise, ccw}

void dfs(int u) {
	if(vis[u] || ok) return;
	vis[u] = 1;

	int i = u / DEG, j = u % DEG;

	int vJ = (j + 1) % DEG;
	if(!gInv[u][2]) dfs(i * DEG + vJ);
	vJ = (j + DEG - 1) % DEG;
	if(!gInv[u][3]) dfs(i * DEG + vJ);

	if(!gInv[u][0]) {
		if(i + 1 == RLIM) ok = 1;
		else dfs(u + DEG);
	}

	if(!gInv[u][1] && i)
		dfs(u - DEG);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		for(int i = 0; i < Z; ++i) for(int j = 0; j < 4; ++j)
			gInv[i][j] = 0;
		for(int i = 0; i < Z; ++i)
			vis[i] = 0;
		ok = 0;

		int N; cin >> N;
		for(int i = 0; i < 4; ++i)
			gInv[Z-1][i] = 1;

		while(N--) {
			char c; cin >> c;
			if(c == 'C') {
				int r, a, b; cin >> r >> a >> b;
				--r;
				if(a < b) {
					for(int i = a; i < b; ++i) {
						gInv[r * DEG + i][0] = 1;
						gInv[r * DEG + DEG + i][1] = 1;
					}
				} else {
					for(int i = a; i != b; ++i %= DEG) {
						gInv[r * DEG + i][0] = 1;
						gInv[r * DEG + DEG + i][1] = 1;
					}
				}
			} else {
				int a, b, t; cin >> a >> b >> t;
				int s = t ? t - 1 : DEG - 1;
				for(int i = a; i < b; ++i) {
					gInv[i * DEG + s][2] = 1;
					gInv[i * DEG + t][3] = 1;
				}
			}
		}

		for(int i = 0; i < DEG; ++i)
			dfs(i);

		cout << (ok ? "YES" : "NO");
		cout << '\n';
	}
}