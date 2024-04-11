#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

const int MAXN = 2000;

bitset<MAXN>G[2][MAXN]; int n;

int abs(int x) {return x >= 0 ? x : -x;}

bool f[2]; int a[2][MAXN + 5];
void get(int o) {
	for(int i=0;i<n;i++) {
		if( a[o][i] == -1 ) {
			for(int j=0;j<n;j++)
				if( (a[o][j] == 0 && G[o][i<<1|1][j<<1|1]) || (a[o][j] == 1 && G[o][i<<1|1][j<<1]) ) {
					a[o][i] = 0;
					break;
				}
			if( a[o][i] == -1 ) a[o][i] = 1;
		}
		printf("%d ", a[o][i]);
	}
	exit(0);
}

int main() {
	int m[2]; scanf("%d%d%d", &n, &m[0], &m[1]);
	for(int o=0;o<2;o++) {
		for(int i=1;i<=m[o];i++) {
			int a, b; scanf("%d%d", &a, &b);
			int p = (a < 0), q = (b < 0); a = abs(a) - 1, b = abs(b) - 1;
			G[o][a<<1|p][b<<1|(!q)] = true, G[o][b<<1|q][a<<1|(!p)] = true;
		}
		for(int i=0;i<(n<<1);i++) G[o][i][i] = true;
		for(int k=0;k<(n<<1);k++)
			for(int i=0;i<(n<<1);i++)
				if( G[o][i][k] ) G[o][i] |= G[o][k];
		for(int i=0;i<n;i++) {
			if( G[o][i<<1][i<<1|1] && G[o][i<<1|1][i<<1] ) {
				f[o] = true;
				break;
			}
			else if( G[o][i<<1][i<<1|1] ) a[o][i] = 1;
			else if( G[o][i<<1|1][i<<1] ) a[o][i] = 0;
			else a[o][i] = -1;
		}
	}
	if( f[0] && f[1] ) puts("SIMILAR");
	else if( f[0] ) get(1);
	else if( f[1] ) get(0);
	else {
		for(int i=0;i<n;i++)
			if( a[0][i] != a[1][i] ) {
				if( a[0][i] == -1 ) a[0][i] = (!a[1][i]), get(0);
				else if( a[1][i] == -1 ) a[1][i] = (!a[0][i]), get(1);
				else get(0);
				return 0;
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) {
				if( a[0][i] == -1 && a[0][j] == -1 ) {
					if( G[0][i<<1|1][j<<1|1] != G[1][i<<1|1][j<<1|1] ) {
						if( G[0][i<<1|1][j<<1|1] == 0 )
							a[0][i] = 1, a[0][j] = 0, get(0);
						else a[1][i] = 1, a[1][j] = 0, get(1);
						return 0;
					}
					else if( G[0][i<<1|1][j<<1] != G[1][i<<1|1][j<<1] ) {
						if( G[0][i<<1|1][j<<1] == 0 )
							a[0][i] = 1, a[0][j] = 1, get(0);
						else a[1][i] = 1, a[1][j] = 1, get(1);
						return 0;
					}
					else if( G[0][i<<1][j<<1|1] != G[1][i<<1][j<<1|1] ) {
						if( G[0][i<<1][j<<1|1] == 0 )
							a[0][i] = 0, a[0][j] = 0, get(0);
						else a[1][i] = 0, a[1][j] = 0, get(1);
						return 0;
					}
					else if( G[0][i<<1][j<<1] != G[1][i<<1][j<<1] ) {
						if( G[0][i<<1][j<<1] == 0 )
							a[0][i] = 0, a[0][j] = 1, get(0);
						else a[1][i] = 0, a[1][j] = 1, get(1);
						return 0;
					}
				}
			}
		puts("SIMILAR");
	}
}