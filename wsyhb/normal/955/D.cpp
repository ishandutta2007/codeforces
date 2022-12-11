#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int max_n=5e5+5;
const int max_m=5e5+5;
char s[max_n],t[max_m];
int pi[max_m],len[max_n];
inline void solve()
{
	pi[1]=0;
	for(int i=2,j=0;i<=m;++i)
	{
		while(j>0&&t[i]!=t[j+1])
			j=pi[j];
		j+=t[i]==t[j+1];
		pi[i]=j;
	}
	for(int i=1,j=0;i<=n;++i)
	{
		while(j>0&&s[i]!=t[j+1])
			j=pi[j];
		j+=s[i]==t[j+1];
		while(j>k)
			j=pi[j];
		len[i]=j;
	}
}
int Left[max_n],Right[max_n];
struct Tree
{
	int type;
	inline Tree(int ty)
	{
		type=ty;
	}
	inline bool cmp(int x,int y)
	{
		return !type?x<y:x>y;
	}
	int End[max_m],Last[max_m],Next[max_m],e;
	inline void add_edge(int x,int y)
	{
		End[++e]=y;
		Next[e]=Last[x];
		Last[x]=e;
	}
	int val[max_m];
	void dfs(int x)
	{
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			dfs(y);
			if(cmp(val[y],val[x]))
				val[x]=val[y];
		}
	}
}TL(0),TR(1);
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,s+1,t+1);
	solve();
	for(int i=1;i<=n;++i)
		Left[i]=len[i];
	int Max=0,id=-1;
	for(int i=1;i<=n;++i)
	{
		if(len[i]>Max)
		{
			Max=len[i];
			id=i;
		}
	}
	if(m<=k&&Max==m)
	{
		int L,R;
		if(id>=2*k)
			R=id-k+1,L=R-k;
		else
			L=1,R=k+1;
		puts("Yes");
		printf("%d %d\n",L,R);
		return 0;
	}
	for(int i=1;i<=m;++i)
		TL.add_edge(pi[i],i);
	for(int i=0;i<=m;++i)
		TL.val[i]=n+1;
	for(int i=n;i>=k;--i)
		TL.val[Left[i]]=i;
	TL.dfs(0);
	reverse(s+1,s+n+1);
	reverse(t+1,t+m+1);
	solve();
	for(int i=1;i<=n;++i)
		Right[i]=len[n+1-i];
	for(int i=1;i<=m;++i)
		TR.add_edge(pi[i],i);
	for(int i=1;i<=n-k+1;++i)
		TR.val[Right[i]]=i;
	TR.dfs(0);
	for(int i=0;i<=m;++i)
	{
		if(TL.val[i]<TR.val[m-i])
		{
			int L=TL.val[i]-k+1;
			int R=TR.val[m-i];
			puts("Yes");
			printf("%d %d\n",L,R);
			return 0;
		}
	}
	puts("No");
	return 0;
}