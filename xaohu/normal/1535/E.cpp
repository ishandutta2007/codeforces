#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 19;
const int M = 19;

int q, a[N], c[N], fa[N][M], dep[N];

int jmp(int u, int k) {
	rep(i, 0, M - 1)
		if (k >> i & 1)
			u = fa[u][i];
	return u;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> q >> a[0] >> c[0];
	rep(n, 1, q) {
		int b;
		cin >> b;
		if (b == 1) {
			cin >> fa[n][0] >> a[n] >> c[n];
			dep[n] = dep[fa[n][0]] + 1;
			rep(i, 1, M - 1)
				fa[n][i] = fa[fa[n][i - 1]][i - 1];
		}
		else {
			int u, w;
			cin >> u >> w;
			int v = u;
			per(i, 0, M - 1) 
				if (a[fa[v][i]])
					v = fa[v][i];
			ll cnt = 0, price = 0;
			per(d, 0, dep[u] - dep[v]) {
				int x = jmp(u, d);
				ll cur = min(w, a[x]);
				cnt += cur;
				price += cur * c[x];
				a[x] -= cur;
				w -= cur;
				if (!w) break;
			}
			cout << cnt << " " << price << endl;
		}
	}		
	return 0;
}