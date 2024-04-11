#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
struct Tree
{
	int child[10];
	int fail;
}tree[50005];
char s[5005],x[105],y[105];
int n,d,tot,a[105];
ll f[55][25005][2];
queue<int>q;
void ins(char*s,int n)
{
	int node=1;
	for(int i=1;i<n;i++)
	{
		if(!tree[node].child[s[i]-'0'])tree[node].child[s[i]-'0']=++tot;
		node=tree[node].child[s[i]-'0'];
	}
	if(!tree[node].child[s[n]-'0'])tree[node].child[s[n]-'0']=2;
}
void build_AC()
{
	tree[1].fail=1;
	q.push(1);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		if(node==2)continue;
		for(int i=0;i<10;i++)
		{
			if(tree[node].child[i])
			{
				if(node==1)tree[tree[node].child[i]].fail=1;
				else tree[tree[node].child[i]].fail=tree[tree[node].fail].child[i];
				q.push(tree[node].child[i]);
			}
			else
			{
				if(node==1)tree[node].child[i]=node;
				else tree[node].child[i]=tree[tree[node].fail].child[i];
			}
		}
	}
	for(int i=0;i<10;i++)tree[2].child[i]=2;
}
void DP()
{
	memset(f,0,sizeof(f));
	f[0][1][1]=1;
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			if(f[i-1][j][0]+f[i-1][j][1]==0)continue;
			f[i-1][j][0]%=MOD;
			f[i-1][j][1]%=MOD;
			for(int now=0;now<10;now++)
			{
				f[i][tree[j].child[now]][0]+=f[i-1][j][0];
				if(now<a[i])f[i][tree[j].child[now]][0]+=f[i-1][j][1];
				if(now==a[i])f[i][tree[j].child[now]][1]+=f[i-1][j][1];
			}
		}
	}
}
int main()
{
	scanf("%s",s+1);
	scanf("%s%s",x+1,y+1);
	n=(int)strlen(s+1);
	d=(int)strlen(x+1);
	tot=2;
	for(int i=0;i+d/2<=n;i++)
	  ins(s+i,d/2);
	build_AC();
	for(int i=1;i<=d;i++)a[i]=y[i]-'0';
	DP();
	ll ans=f[d][2][0]+f[d][2][1];
	for(int i=1;i<=d;i++)a[i]=x[i]-'0';
	DP();
	ans-=f[d][2][0];
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}