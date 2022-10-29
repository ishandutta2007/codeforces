#include <cstdio>
#include <algorithm>
const int maxn = 100005;
int max,n,cnt,a[maxn],d[maxn]; 
int main() {

	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",a + i);
		++d[a[i]];
		if (a[i] > max) max = a[i];
	}
	for (int i = 1; i <= 5000; ++i) {
		if (d[i] > 2) d[i] = 2;
		if (i == max && d[i] == 2) d[i] = 1;
		cnt += d[i];
	}
	printf("%d\n",cnt);
	for (int i = 1; i <= 5000; ++i)
		if (d[i]) printf("%d ",i);
	for (int i = max - 1; i >= 1; --i)
		if (d[i] == 2) printf("%d ",i);
}