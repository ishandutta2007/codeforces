#include <stdio.h>
const int N=105;
int n[N],p[N];
int FindEnd(int x)
{
	while(n[x]) x=n[x];
	return x;
}
int main()
{
	int m,i;
	scanf("%i",&m);
	int t=0;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&p[i],&n[i]);
		if(!p[i]) t=i;
	}
	for(i=1;i<=m;i++)
	{
		if(!p[i] && i!=t)
		{
			int tmp=FindEnd(t);
			n[tmp]=i;
			p[i]=tmp;
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%i %i\n",p[i],n[i]);
	}
	return 0;
}