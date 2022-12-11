#include<bits/stdc++.h>
using namespace std;
int n,m;
long long k;
const int max_n=1e3+5;
char s[max_n];
string S[max_n];
const int max_tot=500*1001+5;
int id[max_tot],pos[max_tot],tot,trans[max_n];
const int max_m=1e3+5;
long long dp[max_m][max_n],val[max_n];
inline bool check(int key)
{
	int id_now=id[key],pos_now=pos[key];
	for(int i=1;i<=n;++i)
	{
		int p=0;
		while(p<=n-i&&p<=pos_now&&s[i+p]==S[id_now][p])
			++p;
		if(p>n-i&&p>pos_now)
			trans[i-1]=n;
		else if(p>n-i)
			trans[i-1]=n+1;
		else if(p>pos_now)
			trans[i-1]=i+p-1;
		else
			trans[i-1]=s[i+p]<S[id_now][p]?n+1:i+p;
	}
	for(int i=0;i<=m;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=0;
	dp[0][0]=1;
	for(int i=0;i<=m-1;++i)
	{
		for(int j=0;j<=n+1;++j)
			val[j]=0;
		for(int j=0;j<=n-1;++j)
			val[trans[j]]=min(val[trans[j]]+dp[i][j],k);
		for(int j=1;j<=n;++j)
		{
			val[j]=min(val[j]+val[j-1],k);
			dp[i+1][j]=val[j];
		}
	}
	return dp[m][n]==k;
}
int main()
{
	scanf("%d%d%lld%s",&n,&m,&k,s+1);
	for(int i=1;i<=n;++i)
	{
		S[i].resize(n-i+1);
		for(int j=i;j<=n;++j)
			S[i][j-i]=s[j];
	}
	sort(S+1,S+n+1);
	for(int i=0;i<int(S[1].size());++i)
		id[++tot]=1,pos[tot]=i;
	for(int i=2;i<=n;++i)
	{
		int p=0;
		while(p<int(S[i].size())&&p<int(S[i-1].size())&&S[i][p]==S[i-1][p])
			++p;
		assert(p<int(S[i].size()));
		for(int j=p;j<int(S[i].size());++j)
			id[++tot]=i,pos[tot]=j;
	}
	int L=1,R=tot,res=-1;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check(mid))
			res=mid,L=mid+1;
		else
			R=mid-1;
	}
	assert(res!=-1);
	for(int i=0;i<=pos[res];++i)
		putchar(S[id[res]][i]);
	putchar('\n');
	return 0;
}