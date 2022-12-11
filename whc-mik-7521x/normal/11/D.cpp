#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[1<<19][20],n,m,si[1<<19],bit[1<<19];
vector<int>ed[30];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y; 
		scanf("%lld%lld",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	for(int i=1,o=1;i<=n;i++,o<<=1){
		dp[o][i]=1;
	}
	int ma=1<<n;
	for(int i=1;i<ma;i++){
		bit[i]=bit[i^(i&-i)]+1;
	}
	for(int i=1,o=1;i<ma;i<<=1,o++){
		si[i]=o;
	}
	for(int i=1;i<ma;i++){
		int j=i&-i;
		for(int o=(i^j)&-(i^j);o;o=(i^j)&-(i^j)){
			j|=o;
			int v=si[o];
			for(int k=0;k<(int)ed[v].size();k++){
				dp[i][v]+=dp[i^o][ed[v][k]];
			}
		}
	}
	int ans=0;
	for(int i=1;i<ma;i++){
		if(bit[i]>=3){
			int p=si[i&-i];
			for(int o=0;o<(int)ed[p].size();o++){
				ans+=dp[i][ed[p][o]];
			}
		}
	}
	printf("%lld",ans/2);
	return 0;
}