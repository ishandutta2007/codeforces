#include <stdio.h>
int sol,n,k;
bool graph[105][105];
int home[105];
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
void work(int pos, int cnt)
{
	sol=max(sol,cnt);
	if(pos>n) return;
	if(n-pos+1+cnt<=sol) return;
	work(pos+1,cnt);
	bool flag=true;
	int i;
	for(i=1;i<=cnt;i++)
	{
		if(!graph[pos][home[i]])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		home[cnt+1]=pos;
		work(pos+1,cnt+1);
	}
}
int main()
{
	scanf("%i %i",&n,&k);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%i",&graph[i][j]);
	work(1,0);
	printf("%.15llf\n",0.5*(sol-1)/sol*k*k);
	return 0;
}