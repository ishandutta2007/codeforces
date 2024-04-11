#include <cstdio>
#include <bitset>
using namespace std;
bitset<500>bts[2][61][500], nw, tmp;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int u, v, p; scanf("%d%d%d", &u, &v, &p), u--, v--;
		bts[p][0][u].set(v, 1);
	}
	for(int p=1;p<=60;p++) {
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++) {
				if( bts[0][p-1][i][k] ) bts[0][p][i] |= bts[1][p-1][k];
				if( bts[1][p-1][i][k] ) bts[1][p][i] |= bts[0][p-1][k];
			}
	}
	int type = 0; nw.set(0, 1);
	long long ans = 0;
	for(int i=60;i>=0;i--) {
		tmp = 0;
		for(int j=0;j<n;j++)
			if( nw[j] && bts[type][i][j].any() )
				tmp |= bts[type][i][j];
		if( tmp.any() ) {
			ans |= (1LL<<i);
			type ^= 1, nw = tmp;
		}
	}
	if( ans > (long long)(1E18) ) puts("-1");
	else printf("%lld\n", ans);
}