#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
void ckmn(ll &x,ll y){x=min(x,y);}
const int N=5005;
vector<pair<int,ll>> dp[2];
int x[N];
pair<int,int> p[N];
int y[N*N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%i",&x[i]);
	sort(x+1,x+1+n);
	for(int i=1;i<=m;i++)scanf("%i %i",&p[i].first,&p[i].second);
	sort(p+1,p+1+m);
	int k=0;
	for(int i=1;i<=m;i++){
		while(p[i].second--)
			y[++k]=p[i].first;
	}
	dp[0].pb({0,0});
	for(int i=1;i<=n;i++){
		int j=lower_bound(y+1,y+1+k,x[i])-y;
		for(int l=max(1,j-n+i-1);l<=min(j+i,k);l++){
			ll now=abs(x[i]-y[l]);
			int h=lower_bound(dp[(i-1)&1].begin(),dp[(i-1)&1].end(),mp(l,(ll)0))-dp[(i-1)&1].begin();
			if(h>0){
				now+=dp[(i-1)&1][h-1].second;
				dp[i&1].pb({l,now});
			}
		}
		for(int l=1;l<dp[i&1].size();l++)
			ckmn(dp[i&1][l].second,dp[i&1][l-1].second);
		dp[(i-1)&1].clear();
	}
	if(dp[n&1].empty())printf("-1\n");
	else printf("%lld\n",dp[n&1].back().second);
	return 0;
}