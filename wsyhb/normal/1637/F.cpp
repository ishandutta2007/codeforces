#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
long long ans;
int h[max_n],mx[max_n];
void dfs(int x,int fa)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			mx[x]=max(mx[x],mx[y]);
		}
	}
	if(mx[x]<h[x])
		ans+=h[x]-mx[x],mx[x]=h[x];
}
int main()
{
	int n;
	scanf("%d",&n);
	int rt=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",h+i);
		if(h[i]>h[rt])
			rt=i;
	}
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	vector<int> val(1,0);
	for(int i=Last[rt];i;i=Next[i])
	{
		int y=End[i];
		dfs(y,rt);
		val.push_back(mx[y]);
	}
	assert((int)val.size()>=2);
	nth_element(val.begin(),val.begin()+1,val.end(),greater<int>());
	assert(val[0]<=h[rt]&&val[1]<=h[rt]);
	ans+=(h[rt]-val[0])+(h[rt]-val[1]);
	printf("%lld\n",ans);
	return 0;
}