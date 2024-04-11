#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N=2102;
const int inf=1e9+7;
char word[N],ch[N],tr[N];
int go[N*N][26],cnt,root;
pair<int,int> x[N*N];
void Set(int &c, int k, int n, int i)
{
	if(!c) c=++cnt;
	if(k!=i)
	{
		x[c].first=k-1;
		x[c].second=i;
	}
	if(k==n+1) return;
	Set(go[c][tr[k]-'a'],k+1,n,i);
}
void Set2(int &c, int k, int i)
{
	if(!c) c=++cnt;
	if(k!=i)
	{
		x[c].first=k+1;
		x[c].second=i;
	}
	if(!k) return;
	Set2(go[c][tr[k]-'a'],k-1,i);
}
int dp[N],par[N];
pair<int,int> y[N]; 
vector< pair<int,int> > sol;
int main()
{
	int n,m,i,j;
	scanf("%s",word+1);
	m=strlen(word+1);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=m;i++) tr[i]=word[i];
	for(i=1;i<=m;i++) Set(root,i,m,i);
	for(i=1;i<=m;i++) Set2(root,i,i);
	for(i=1;i<=n;i++)
	{
		dp[i]=inf;
		int c=root;
		for(j=i;j;j--)
		{
			c=go[c][ch[j]-'a'];
			if(x[c].first)
			{
				if(dp[j-1]+1<dp[i])
				{
					dp[i]=dp[j-1]+1;
					par[i]=j-1;
					y[i]=x[c];
				}
			}
			if(!c) break;
		}
	}
	if(dp[n]==inf) return printf("-1\n"),0;
	int c=n;
	while(c)
	{
		sol.push_back(y[c]);
		c=par[c];
	}
	reverse(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}