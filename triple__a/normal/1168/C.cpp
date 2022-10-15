#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int maxm=20;
const int maxn=300007;
int a[maxn],dgt[maxn][maxm],dp[maxn][maxm],pt[maxm];

bool solve(int s,int t){
	for (int i=0;i<maxm;++i){
		if (dgt[t][i]&dp[s][i]<=t){
			return 1;
		}
	}
	return 0;
}
int main(){
	memset(dgt,0,sizeof(dgt));
	memset(dp,0,sizeof(dp));
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i){
		int t=0,c;
		scanf("%d",&a[i]);
		c=a[i];
		while(c){
			dgt[i][t++]=c&1;
			c>>=1;
		}
	}
	for (int i=0;i<maxm;++i){
		dgt[n+1][i]=1;
		dp[n+1][i]=n+1;
		pt[i]=n+1;
	}
	for (int i=n;i>0;--i){
		for (int j=0;j<maxm;++j){
			int ans=n+1;
			for (int k=0;k<maxm;++k){
				if (dgt[i][k]){
					if (dgt[pt[k]][j]){
						ans=min(ans,pt[k]);
					}
					else{
						ans=min(ans,dp[pt[k]][j]);
					}
				}
			}
			dp[i][j]=ans;
		}
		for (int j=0;j<maxm;++j){
			if (dgt[i][j]){
				pt[j]=i;
			}
		}
	}
	while(q--){
		int s, t;
		scanf("%d%d",&s,&t);
		if (solve(s,t)){
			printf("Shi\n");
		}
		else{
			printf("Fou\n");
		}
	}
	return 0;
}