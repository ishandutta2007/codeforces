#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
double ans;
int n, m, x, y, z, a[1111];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ans = 0;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if((double)(a[x] + a[y]) / z > ans) ans = (double)(a[x] + a[y]) / z;
	}
	printf("%.10f\n", ans);
	fclose(stdin);

	return 0;
}