#include "bits/stdc++.h"

using namespace std;

const int N = 505, M = 500005;

int n,m,L;
bitset<N> f1[105][N], g1[105][N], f2[105][N], g2[105][N];
bitset<N> a1[N], b1[N], a2[N], b2[N], f3[N], g3[N], f4[N], g4[N];

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen ("d.in","r",stdin);
		freopen ("d.out","w",stdout);
	#endif
	
	cin >> n >> m; int u, v, w;
	bool tag = false;
	for (int i = 1; i <= m; i ++){
		scanf ("%d%d%d", &u, &v, &w);
		if (w == 0) f1[0][u][v] = 1, f2[0][v][u] = 1, tag = true;
		else g1[0][u][v] = 1, g2[0][v][u] = 1;
	}
	if (tag == false) {puts("0"); return 0;}
	
	// f1[u][v] = f1[u][d] & g2[v][d] <==> f1[u] & g2[v] != 0
	// f2[u][v] = f1[v][u] = f1[v] & g2[u] != 0
	// g1[u][v] = g1[u][d] & f2[v][d] <==> f2[v] & g1[u] != 0
	// g2[u][v] = g1[v][u] = f2[u] & g1[v] != 0
	
	typedef long long LL;
	const LL inf = (LL)1e18;
	for (register long long i = 1, l = 1; i <= inf*2; i <<= 1, l ++){
		bool flag = false;
		for (register int j = 1; j <= n; j ++){
			for (register int k = 1; k <= n; k ++){
				f1[l][j][k] = !!((f1[l-1][j]&g2[l-1][k]).any());
				f2[l][j][k] = !!((f1[l-1][k]&g2[l-1][j]).any());
				g1[l][j][k] = !!((f2[l-1][k]&g1[l-1][j]).any());
				g2[l][j][k] = !!((f2[l-1][j]&g1[l-1][k]).any());
				if (f1[l][j][k]) flag = true;
			}
		}
		if (flag == false){L = l; break;}
	}
	
	if (L == 0) {puts("-1"); return 0;}
	
	for (int i = 1; i <= n; i ++)
		a1[i] = f1[L-1][i], a2[i] = f2[L-1][i], b1[i] = g1[L-1][i], b2[i] = g2[L-1][i];
	
	LL ans = 1LL << (L-1);
	bool __begin_g = true;
	
	for (register int i = L-2; i >= 0; i --){
		bool flag = false;
		for (register int j = 1; j <= n; j ++){
			for (register int k = 1; k <= n; k ++){
				if (__begin_g){
					f3[j][k] = !!((a1[j]&g2[i][k]).any());
					f4[j][k] = !!((a1[k]&g2[i][j]).any());
					g3[j][k] = !!((b1[j]&f2[i][k]).any());
					g4[j][k] = !!((b1[k]&f2[i][j]).any());
				} else {
					f3[j][k] = !!((a1[j]&f2[i][k]).any());
					f4[j][k] = !!((a1[k]&f2[i][j]).any());
					g3[j][k] = !!((b1[j]&g2[i][k]).any());
					g4[j][k] = !!((b1[k]&g2[i][j]).any());
				}
				if (f3[j][k]) flag = true;
			}
		}
		if (flag == true){
			for (int k = 1; k <= n; k ++)
				a1[k] = f3[k], a2[k] = f4[k], b1[k] = g3[k], b2[k] = g4[k];
			ans += 1LL << i;
			__begin_g ^= 1;
		}
	}
	
	if (ans > inf) ans = -1;
	cout << ans << endl;
	
	return 0;
}