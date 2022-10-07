#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,cnt;
bool flag[1005],now[1005];
int main()
{
	scanf("%d",&n);
	x=1;
	for(int i=2;i<=n;i++)
	  if(n/x+x-(n%x==0)>n/i+i-(n%i==0))
	    x=i;
	for(int i=1;i<=n;i++)
	  if(i%x)flag[i]=1;
	flag[n]=0;
	while(cnt<n-(n/x+x-(n%x==0)))
	{
		printf("%d ",x);
		int rest=x;
		for(int i=1;rest;i++)
		  if(flag[i]&&!now[i])
		    printf("%d ",i),now[i]=1,rest--,cnt++;
		printf("\n");
		fflush(stdout);
		int p;
		scanf("%d",&p);
		for(int i=0;i<x;i++)
		{
			if(now[(i+p-1)%n+1])cnt--;
			now[(i+p-1)%n+1]=0;
		}
	}
	printf("0\n");
	return 0;
}