#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
const long long INF=1e14;
int n,m,k,q;
vector<int> a[maxn];
int sf[maxn],sfl[maxn],sfr[maxn],cnt=0;
long long dp[7][4],pos[7];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1;i<=k;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u].push_back(v);
	}
	for (int i=1;i<=q;++i){
		scanf("%d",&sf[i]);
	}
	sort(sf+1,sf+1+q);
	sf[q+1]=m+1;
	for (int i=1;i<=q;++i){
		for (int j=sf[i];j<sf[i+1];++j){
			sfl[j]=sf[i];
		}
		for (int j=sf[i-1]+1;j<=sf[i];++j){
			sfr[j]=sf[i];
		}
	}
	memset(dp,0,sizeof(dp));
	for (int l=1;l<=4;++l){
		pos[l]=1;
	}
	while (1){
		if (!a[n].size()){
			n--;
		}
		else{
			break;
		}
	}
	for (int i=1;i<=n;++i){
		if (!a[i].size()){
			if (i==1){
				for (int j=1;j<=4;++j){
					dp[j][0]=sf[1];
					pos[j]=sf[1];
				}
				continue;
			}
			for (int j=1;j<=4;++j){
				dp[j][0]++;
			}
			continue;
		}
		sort(a[i].begin(),a[i].end());
		int tmp[7];
		tmp[1]=sfl[a[i][0]],tmp[2]=sfr[a[i][0]],tmp[3]=sfl[a[i][a[i].size()-1]],tmp[4]=sfr[a[i][a[i].size()-1]];
		if (i==n){
			tmp[1]=tmp[2]=a[i][0],tmp[3]=tmp[4]=a[i][a[i].size()-1];
		}
		for (int j=1;j<=4;++j){
			dp[j][1]=INF;
			if (!tmp[j]){
				continue;
			}
			for (int k=1;k<=4;++k){
				dp[j][1]=min(dp[j][1],dp[k][0]+min(abs(pos[k]-a[i][0])+abs(a[i][a[i].size()-1]-tmp[j]),abs(pos[k]-a[i][a[i].size()-1])+abs(tmp[j]-a[i][0]))+a[i][a[i].size()-1]-a[i][0]+1);
			}
		}
		for (int j=1;j<=4;++j){
			pos[j]=tmp[j];
			dp[j][0]=dp[j][1];
//			cout<<dp[j][0]<<" ";
		}
//		cout<<endl;
	}
	long long ans=INF;
	for (int i=1;i<=4;++i){
		ans=min(ans,dp[i][0]);
	}
	cout<<ans-1-cnt<<endl;
	return 0;
}