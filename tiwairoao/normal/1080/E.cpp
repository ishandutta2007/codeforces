#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 250;
char s[MAXN + 5][MAXN + 5];
int a[2*MAXN + 5][26], tot[2*MAXN + 5], p[2*MAXN + 5];
bool cmp(int x, int y) {
	if( tot[x] > 1 || tot[y] > 1 ) return false;
	for(int i=0;i<26;i++)
		if( a[x][i] != a[y][i] ) return false;
	return true;
}
int main() {
	int n, m; long long ans = 0;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%s", s[i]+1);
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++)
			for(int k=0;k<26;k++)
				a[2*j-1][k] = tot[2*j-1] = 0;
		for(int j=i;j<=m;j++) {
			for(int k=1;k<=n;k++) {
				if( a[2*k-1][s[k][j]-'a'] & 1 )
					tot[2*k-1]--;
				else tot[2*k-1]++;
				a[2*k-1][s[k][j]-'a']++;
			}
			int mxp = 0; p[0] = 1;
			for(int k=1;k<=2*n;k++) {
				if( mxp + p[mxp] <= k ) p[k] = 1;
				else p[k] = min(p[2*mxp-k], mxp+p[mxp]-k);
				while( k-p[k] >= 0 && k+p[k] <= 2*n && cmp(k-p[k], k+p[k]))
					p[k]++;
				if( k + p[k] > mxp + p[mxp] ) mxp = k;
				if( tot[k] <= 1 ) ans += p[k]/2;
			}
		}
	}
	printf("%I64d\n", ans);
}