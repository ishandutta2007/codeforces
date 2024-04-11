#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 200005;
int a[maxn],b[maxn],v[maxn * 2];
int n,m,max,ma,mb,t,suma[maxn * 2],sumb[maxn * 2];
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d",a + i), v[++t] = a[i];
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i) scanf("%d",b + i), v[++t] = b[i];
	
	v[++t] = 0;
	std::sort(v + 1,v + t + 1);
	t = std::unique(v + 1,v + t + 1) - v - 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = std::lower_bound(v + 1,v + t + 1,a[i]) - v;
		++suma[a[i]];
	}
	for (int i = 1; i <= m; ++i) {
		b[i] = std::lower_bound(v + 1,v + t + 1,b[i]) - v;	
		++sumb[b[i]];
	}
	for (int i = 1; i <= t; ++i) suma[i] += suma[i - 1], sumb[i] += sumb[i - 1];	
	
	max = -100000000;
	for (int i = 1; i <= t; ++i) {
		int a = suma[i] * 2 + (n - suma[i]) * 3,
		b = sumb[i] * 2 + (m - sumb[i]) * 3;
		if (a - b > max) {
			max = a - b;
			ma = a; mb = b;
		}
		else if (a - b == max && a > ma) {
			ma = a; mb = b;
		}
	}
	printf("%d:%d\n",ma,mb);
}