#include<bits/stdc++.h>
using namespace std;
int n,k;
const int max_n=1e6+5;
char S[max_n];
int pi[max_n];
vector<int> edge[max_n];
namespace BIT
{
	int val[max_n];
	inline void modify(int k,int v)
	{
		for(int i=++k;i<=n+1;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=++k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}
bool ans[max_n];
void dfs(int x)
{
	if(x)
		ans[x]=BIT::query(x-(x+k)/(k+1))-BIT::query(x-x/k-1);
	BIT::modify(x,1);
	for(int i=0;i<int(edge[x].size());++i)
		dfs(edge[x][i]);
	BIT::modify(x,-1);
}
int main()
{
	scanf("%d%d%s",&n,&k,S+1);
	pi[1]=0;
	for(int i=2,j=0;i<=n;++i)
	{
		while(j>0&&S[i]!=S[j+1])
			j=pi[j];
		j+=S[i]==S[j+1];
		pi[i]=j;
	}
	for(int i=1;i<=n;++i)
		edge[pi[i]].push_back(i);
	dfs(0);
	for(int i=1;i<=n;++i)
		putchar(ans[i]+'0');
	putchar('\n');
	return 0;
}