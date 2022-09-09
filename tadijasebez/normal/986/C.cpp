#include <stdio.h>
const int N=1<<23;
bool was[N][2],in[N];
int n;
void DFS(int x, int t)
{
	if(was[x][t] || (t==2 && !in[x])) return;
	was[x][t]=1;
	if(t==2) DFS(x,1);
	else
	{
		DFS(((1<<n)-1)^x,2);
		for(int i=0;i<n;i++)
		{
			if((x>>i)&1) continue;
			DFS(x^(1<<i),1);
		}
	}
}
int a[N];
int main()
{
	int i,m,x,sol=0;
	scanf("%i %i",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%i",&a[i]);
		in[a[i]]=1;
	}
	for(i=0;i<m;i++)
	{
		if(was[a[i]][2]) continue;
		sol++;
		DFS(a[i],2);
	}
	printf("%i\n",sol);
	return 0;
}