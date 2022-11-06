#include<stdio.h>
int main()
{
	int i, j, n, s = 0, t, q;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<i; j++)scanf("%*d");
		scanf("%d", &t);
		(s+=t)%=2;
		for(j=i+1; j<=n; j++) scanf("%*d");
	}
	scanf("%d", &q);
	for(i=1; i<=q; i++)
	{
		scanf("%d", &t);
		if(t==3) printf("%d", s);
		else
		{
			scanf("%*d");
			s = 1-s;
		}
	}
	return 0;
}