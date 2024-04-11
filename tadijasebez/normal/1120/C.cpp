#include <bits/stdc++.h>
using namespace std;
const int N=10050;
const int L=15;
int tot,id[N],sa[N],lcp[N],rmq[N][L];
char s[N];
pair<pair<int,int>,int> tmp[N];
void BuildSuffixArray()
{
	s[++tot]='a'+26;
	for(int i=1;i<=tot;i++) id[i]=s[i]-'a';
	for(int j=0;j<15;j++)
	{
		for(int i=1;i<=tot;i++) tmp[i]={{id[i],id[i+(1<<j)]},i};
		sort(tmp+1,tmp+1+tot);
		int c=0;
		for(int i=1;i<=tot;i++)
		{
			id[tmp[i].second]=c+1;
			c+=i==tot||tmp[i].first!=tmp[i+1].first;
		}
		if(c==tot) break;
	}
	for(int i=1;i<=tot;i++) sa[id[i]]=i;
}
void BuildLCPArray()
{
	int k=0;
	for(int i=1;i<=tot;i++)
	{
		if(id[i]==tot) continue;
		int j=sa[id[i]+1];
		while(s[i+k]==s[j+k]) k++;
		lcp[id[i]]=k;
		if(k) k--;
	}
}
void BuildSparseTable()
{
	for(int i=1;i<=tot;i++) rmq[i][0]=lcp[i];
	for(int j=1;j<L;j++)
	{
		for(int i=1;i<=tot-(1<<j)+1;i++)
		{
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
		}
	}
}
int LCP(int x, int y)
{
	if(x==y) return tot-x;
	x=id[x];y=id[y];
	if(x>y) swap(x,y);
	y--;
	int k=__builtin_clz(1)-__builtin_clz(y-x+1);
	return min(rmq[x][k],rmq[y-(1<<k)+1][k]);
}
char t[N];
int dp[N];
int main()
{
	int n,a,b;
	scanf("%i %i %i",&n,&a,&b);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++) s[i]=t[n-i+1];
	tot=n;
	BuildSuffixArray();
	BuildLCPArray();
	BuildSparseTable();
	for(int i=1;i<=n;i++)
	{
		int l=0;
		for(int j=1;j<i;j++) l=max(l,min(LCP(n-i+1,n-j+1),i-j));
		dp[i]=dp[i-1]+a;
		for(int j=1;j<=l;j++) dp[i]=min(dp[i],dp[i-j]+b);
	}
	printf("%i\n",dp[n]);
	return 0;
}