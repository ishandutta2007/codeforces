// CF 812K
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int n,k,dp[111111][2];
vector<pair<int,int> > v[111111];
pair<int,int> p[111111];
void dfs(int u,int fa)
{
	int i,s,j,x,y;
	s=v[u].size();
	if(u!=0&&s==1)
		return;
	for(i=0;i<s;i=i+1){
		x=v[u][i].first;
		if(x!=fa){
			dfs(x,u);
		}
	}
	j=0;
	//memset(p,0,sizeof(p));
	for(i=0;i<s;i=i+1){
		x=v[u][i].first;
		y=v[u][i].second;
		if(x!=fa){
			j++;
			p[j]=make_pair(dp[x][1]+y,dp[x][0]+y);
		}
	}
	sort(p+1,p+j+1);
	reverse(p+1,p+j+1);
	dp[u][1]=0;
	for(i=1;i<=j&&i<k;i=i+1){
		dp[u][1]+=p[i].first;
	}
	dp[u][0]=dp[u][1];
	for(i=1;i<=j;i=i+1){
		if(i<k)
			dp[u][0]=max(dp[u][0],dp[u][1]-p[i].first+p[i].second+p[k].first);
		else
			dp[u][0]=max(dp[u][0],dp[u][1]+p[i].second);
	}
	for(i=0;i<=j+1;i=i+1)
		p[i]=make_pair(0,0);
}
int main()
{
	int i,x,y,c;
	cin>>n>>k;
	for(i=1;i<n;i=i+1){
		cin>>x>>y>>c;
		v[x].push_back(make_pair(y,c));
		v[y].push_back(make_pair(x,c));
	}
	dfs(0,-1);
	//for(i=0;i<n;i=i+1)
	//	cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<endl;
	cout<<dp[0][0]<<endl;
	return 0;
}