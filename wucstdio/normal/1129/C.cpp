#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int m,a[3005];
ll f[3050];
struct Tree
{
	int child[2];
	int len;
	int fail;
}tree[6005];
int n,tot,last,p[30005];
void insert(int c)
{
	int now=++tot,node=last;
	tree[now].len=tree[node].len+1;
	while(node!=-1&&!tree[node].child[c])
	{
		tree[node].child[c]=now;
		node=tree[node].fail;
	}
	if(node==-1)tree[now].fail=0;
	else
	{
		int cur=tree[node].child[c];
		if(tree[cur].len==tree[node].len+1)tree[now].fail=cur;
		else
		{
			int clone=++tot;
			tree[clone]=tree[cur];
			p[clone]=p[cur];
			tree[clone].len=tree[node].len+1;
			while(node!=-1&&tree[node].child[c]==cur)
			{
				tree[node].child[c]=clone;
				node=tree[node].fail;
			}
			tree[cur].fail=tree[now].fail=clone;
		}
	}
	last=now;
}
int main()
{
	tree[0].fail=-1;
	scanf("%d",&m);
	ll ans=0;
	for(int n=1;n<=m;n++)
	{
		scanf("%d",&a[n]);
		insert(a[n]);
		p[last]=n;
		memset(f,0,sizeof(f));
		f[n+1]=1;
		for(int i=n;i>=1;i--)
		{
			f[i]=f[i+1]+f[i+2]+f[i+3]+f[i+4];
			if(!a[i]&&!a[i+1]&&a[i+2]&&a[i+3])f[i]-=f[i+4];
			if(!a[i]&&a[i+1]&&!a[i+2]&&a[i+3])f[i]-=f[i+4];
			if(a[i]&&a[i+1]&&a[i+2]&&!a[i+3])f[i]-=f[i+4];
			if(a[i]&&a[i+1]&&a[i+2]&&a[i+3])f[i]-=f[i+4];
			f[i]%=MOD;
			ans+=f[i];
		}
		int node=tree[last].fail;
		for(int i=tree[node].len;i>=1;i--)
		  ans-=f[n-i+1];
		ans%=MOD;
		printf("%I64d\n",ans);
	}
	return 0;
}