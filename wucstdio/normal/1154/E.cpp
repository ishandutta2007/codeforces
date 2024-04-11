#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,a[200005],ans[200005],p[200005];
int pre[200005],nxt[200005],head,tail,rest;
bool flag[200005];
void del(int x)
{
	rest--;
	if(x==head)head=nxt[x],pre[nxt[x]]=0;
	else if(x==tail)tail=pre[x],nxt[pre[x]]=0;
	else
	{
		pre[nxt[x]]=pre[x];
		nxt[pre[x]]=nxt[x];
	}
	flag[x]=1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	pre[1]=nxt[n]=0;
	head=1,tail=n;
	rest=n;
	int maxx=n;
	int now=2;
	while(rest)
	{
		if(now==1)now++;
		else now--;
		while(flag[p[maxx]])maxx--;
		int x=p[maxx];
		ans[x]=now;
		del(x);
		for(int i=1;i<=k;i++)
		{
			x=pre[x];
			ans[x]=now;
			if(x)del(x);
			else break;
		}
		x=p[maxx];
		for(int i=1;i<=k;i++)
		{
			x=nxt[x];
			ans[x]=now;
			if(x)del(x);
			else break;
		}
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}