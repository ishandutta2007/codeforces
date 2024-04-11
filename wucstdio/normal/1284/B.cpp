#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Node
{
	int v;
	bool flag;
}b[200005];
int n,a[100005],minv[100005],maxv[100005],num,top;
bool flag[100005];
bool cmp(Node a,Node b)
{
	return a.v<b.v||(a.v==b.v&&a.flag>b.flag);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l;
		scanf("%d",&l);
		minv[i]=1000000000,maxv[i]=0;
		for(int j=1;j<=l;j++)
		{
			int v;
			scanf("%d",&v);
			if(j!=1&&v>minv[i])flag[i]=1;
			minv[i]=min(minv[i],v);
			maxv[i]=max(maxv[i],v);
		}
		if(flag[i])num++;
		else
		{
			b[++top].v=minv[i];
			b[top].flag=0;
			b[++top].v=maxv[i];
			b[top].flag=1;
		}
	}
	sort(b+1,b+top+1,cmp);
	ll ans=0;
	ans=2ll*num*(n-num)+1ll*num*num;
	int now=0;
	for(int i=1;i<=top;i++)
	{
		if(b[i].flag==0)now++;
		else ans+=now;
	}
	printf("%lld\n",ans);
	return 0;
}