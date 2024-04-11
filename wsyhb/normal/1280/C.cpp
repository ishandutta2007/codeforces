#include<bits/stdc++.h>
using namespace std;
const int max_k=1e5+5;
int End[max_k<<2],Last[max_k<<1],Next[max_k<<2],Len[max_k<<2],E=1;
inline void add_edge(int x,int y,int z)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E,Len[E]=z;
	End[++E]=x,Next[E]=Last[y],Last[y]=E,Len[E]=z;
}
int sz[max_k<<1],fath[max_k<<1];
void dfs(int x,int fa)
{
	fath[x]=fa;
	sz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=2*k-1;++i)
		{
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			add_edge(a,b,t);
		}
		dfs(1,0);
		long long G=0,B=0;
		for(int i=2;i<=E;i+=2)
		{
			int x=End[i],y=End[i^1];
			if(fath[x]!=y)
				swap(x,y);
			if(sz[x]&1)
				G+=Len[i];
			B+=1ll*min(sz[x],2*k-sz[x])*Len[i];
		}
		printf("%lld %lld\n",G,B);
		E=1;
		for(int i=1;i<=2*k;++i)
			Last[i]=0;
	}
	return 0;
}