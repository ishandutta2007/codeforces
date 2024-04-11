#include <cstdio>
#include <cstring>
#include <algorithm>
int n,l,a[1005];
double s;
int main() {
	scanf("%d%d",&n,&l);
	for (int i = 1; i <= n; ++i) 
		scanf("%d",a + i);
	std::sort(a + 1, a + n + 1);
	s = std::max(a[1] - 0, l - a[n]);
	for (int i = 2; i <= n; ++i)
		s = std::max(s, (a[i] - a[i - 1]) / 2.0);
	printf("%lf\n",s);
}