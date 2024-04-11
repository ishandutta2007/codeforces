#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
struct node{int to,next;}e[N<<1];
int head[N],n,cnt,dep[N],d[N][20],flag[N],k;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;d[x][0]++;}
int main()
{
	scanf("%d%d",&n,&k);memset(head,-1,sizeof(head));if(k>=15||n<=3)return puts("No"),0;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	int sum=n;
	for(int p=1;p<=k;p++)
	{
		for(int i=1;i<=n;i++)if(d[i][p-1]==1)
		{
			for(int j=head[i];j!=-1;j=e[j].next)
			{
				int v = e[j].to;
				if(flag[v])continue;
				if(!flag[v]&&d[v][p-1]==1)return puts("No"),0;
				d[v][p]++;
			}
			flag[i]=1,sum--;
		}
		for(int i=1;i<=n;i++)
		{
			if(!d[i][p]||flag[i])continue;
			if(d[i][p]<=2)return puts("No"),0;
			d[i][p]=1;
		}
		if(sum==1)
		{
			if(p==k)
				printf("Yes\n");
			else
				printf("No\n");
			return 0;
		}
	}
	puts("No");
}