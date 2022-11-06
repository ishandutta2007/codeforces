#include<stdio.h>
int main()
{
	int n, s, i, ans = -1;
	scanf("%d%d", &n, &s);
	for(i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(x>s || (x==s && y>0)) continue;
		y = 100-y;
		y%=100;
		if(ans<y) ans = y;
	}
	printf("%d", ans);
	return 0;
}