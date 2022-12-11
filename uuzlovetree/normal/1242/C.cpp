#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k;
ll s,sum[16];
vector<ll> a[16];
unordered_map<ll,int> has[16];
bool vis[16];
bool iscir[40005],dp[40005];
int pp[40005];
struct Node
{
	int from,to;
	ll val;
	Node(int F=0,int T=0,ll V=0){from=F;to=T;val=V;}
};
bool operator < (Node A,Node B){return A.from<B.from;}
vector<Node> Ans[40005];
void go(int pos,ll val)
{
	memset(vis,0,sizeof(vis));
	int u=pos;
	ll w=s+val-sum[u];
	vector<Node> tmp;tmp.clear();
	while(1)
	{
		int pre=-1;
		for(int i=0;i<k;++i)if(has[i][w]){pre=i;break;}
		if(pre==-1)return;
		tmp.push_back(Node(pre,u,w));
		u=pre;
		if(vis[u])return;
		vis[u]=1;
		if(u==pos)break;
		w=s+w-sum[u];
	}
	if(val!=w)return;
	int S=0;
	for(int i=0;i<k;++i)if(vis[i])S|=(1<<i);
	iscir[S]=1;
	Ans[S]=tmp;
}
vector<Node> res;
void print(int S)
{
	if(!S)return;
	for(Node u:Ans[S^pp[S]])res.push_back(u);
	print(pp[S]);
}
int main()
{
	scanf("%d",&k);
	s=0;
	for(int sz,i=0;i<k;++i)
	{
		scanf("%d",&sz);
		while(sz--)
		{
			ll x;scanf("%I64d",&x);
			a[i].push_back(x);
			has[i][x]=1;
			sum[i]+=x;
		}
		s+=sum[i];
	}
	if(s%k)puts("No");
	else
	{
		s/=k; 
		for(int i=0;i<k;++i)
			for(ll x:a[i])go(i,x);
		dp[0]=1;
		for(int S=1;S<(1<<k);++S)
		{
			for(int s=S;s;s=(s-1)&S)if(dp[S^s]&iscir[s])
			{
				dp[S]=1;
				pp[S]=S^s;
			}
		}
		if(!dp[(1<<k)-1])puts("No");
		else
		{
			puts("Yes");
			res.clear();
			print((1<<k)-1);
			sort(res.begin(),res.end());
			for(Node u:res)printf("%I64d %d\n",u.val,u.to+1);
		}
	}
}