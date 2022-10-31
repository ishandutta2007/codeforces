#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000;

int c[105], n, x;

double f[105][MAXN + 5];
int main() {
	scanf("%d%d", &n, &x); for(int i=1;i<=n;i++) scanf("%d", &c[i]);
	
	int s = 0; f[0][0] = 1;
	for(int i=1;i<=n;s+=c[i],i++) {
		for(int j=s;j>=0;j--)
			for(int k=i-1;k>=0;k--)
				f[k + 1][j + c[i]] += f[k][j]*(k + 1)/(n - k);
	}
	
	double ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=s;j++)
			ans += f[i][j]*min(1.0*(n+i)/(2*i)*x, 1.0*j/i);
	printf("%.9f\n", ans);
}