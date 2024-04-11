#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;
#define N 200005
int sum[N],last[N],a[N],b[N],n,Q,pos,flag;
void fix(int x){for(;x<N;x+=x&-x)sum[x]++;}
int find(int x){int ret=0;for(;x;x-=x&-x)ret+=sum[x];return ret;}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){if(a[i]==0)pos=i;if(a[i]==Q)flag=1;}
	for(int i=1,lst=0;i<=n;i++)
	{
		if(a[i])lst=a[i],b[i]=a[i];
		else b[i]=max(b[i],lst);
	}
	for(int i=n,lst=0;i;i--)
	{
		if(a[i])lst=a[i];
		else b[i]=max(b[i],lst);
	}
	if(!b[1])
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%d ",Q);puts("");return 0;
	}memset(last,-1,sizeof(last));
	for(int i=1;i<=n;i++)
	{
		if(last[b[i]]==-1)last[b[i]]=find(b[i]-1);
		else if(find(b[i]-1)!=last[b[i]]){puts("NO");return 0;}
		fix(b[i]);
	}
	if(!flag&&!pos){puts("NO");return 0;}
	if(!flag)b[pos]=Q;
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");return 0;
}