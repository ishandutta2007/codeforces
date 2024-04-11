#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
const int maxn = 5005;
int T,n,t[maxn];
double p[maxn],fpre[maxn],dpre[maxn],f[maxn][maxn],d[maxn],tt[maxn];
int main() {
	scanf("%d%d",&n,&T);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf%d",p + i,t + i);
		tt[i] = 1;
		p[i] = p[i] / 100;
		for (int j = 1; j < t[i]; ++j) tt[i] = tt[i] * (1 - p[i]);
	}
	
	if (t[1] != 1) f[1][1] = p[1];
	else f[1][1] = 1;
	if (t[2] != 1) dpre[1] = f[1][1];
	double s = 1;
	for (int i = 2; i <= T; ++i) {
		double tt = 1;
		for (int k = 1; k < t[2]; ++k) tt = tt * (1 - p[2]); 
		s = s * (1 - p[1]);
		f[1][i] = s * p[1];
		if (i == t[1]) f[1][i] = s;
		if (i > t[1]) f[1][i] = 0;
		dpre[i] = dpre[i - 1] * (1 - p[2]) + f[1][i];
		if (i >= t[2]) dpre[i] -= f[1][i - t[2] + 1] * tt;
	}
	for (int i = 2; i <= n; ++i) {
		//memset(d,0,sizeof(d));
		for (int j = 1; j <= T; ++j) {
			f[i][j] = dpre[j - 1] * p[i];
			if (j > t[i]) f[i][j] += f[i - 1][j - t[i]] * tt[i];
			d[j] = d[j - 1] * (1 - p[i + 1]) + f[i][j];
			if (j >= t[i + 1]) d[j] -= f[i][j - t[i + 1] + 1] * tt[i + 1];
		}
		memcpy(dpre,d,sizeof(d));
	}
	double ans = 0;
	for (int i = 1; i <= T; ++i) 
		ans += f[n][i] * n;
	for (int i = 1; i < n; ++i) {
		double tt = 1;
		for (int j = 0; j < t[i + 1]; ++j) {
			ans += f[i][T - j] * i * tt;
			tt = tt * (1 - p[i + 1]);
		}
	}
	printf("%.8lf\n",ans);
}