#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 3e5 + 1;
const int LOG = 22;

ll pref[N], cost[N], a[N], c[N];
int par[N][LOG], dep[N],  nxt[N];

int dizi(int u, int k) {
	for (int i = LOG - 1; i >= 0; i--) {
		if (k & (1 << i)) {
			u = par[u][i];
		}
	}
	return u;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < LOG; j++) {
			par[i][j] = -1;
		}
		nxt[i] = -1;
	}
  int q;
	cin >> q >> a[0] >> c[0];
	pref[0] = a[0];
	cost[0] = a[0] * 1LL * c[0];
	for (int j = 1; j <= q; j++) {
		int type;
		cin >> type;
		if (type == 1) {
			int p;
			cin >> p >> a[j] >> c[j];
			pref[j] = pref[p] + a[j], cost[j] = cost[p] + a[j] * 1LL * c[j], dep[j] = dep[p] + 1, par[j][0] = p;
			for (int i = 1; i < LOG; i++) {
				par[j][i] = dizi(p, (1 << i) - 1);
			}
		} else {
			int v;
			ll w;
			cin >> v >> w;
			int od = v;
			for (int i = LOG - 1; i >= 0; i--) {
				if (a[par[od][i]]) {
					od = par[od][i];
				}
			}
			int visina = dep[od];
			long long uzeo = 0, suma = 0;
			while (w > 0 && visina <= dep[v]) {
				int u = dizi(v, dep[v] - visina);
				visina++;
				int x = min(a[u], w);
				uzeo += x, a[u] -= x, w -= x, suma += x * c[u];
			}
			cout << uzeo << " " << suma << endl;
		}
	}
}