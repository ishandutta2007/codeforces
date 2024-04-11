#include <bits/stdc++.h>
using namespace std;
const int N=3005;
const int inf=1e9+7;
int a[N],b[N],ord[N],dp[N][N],cnt[N];
int main(){
	int n,p,s;
	scanf("%i %i %i",&n,&p,&s);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++)scanf("%i",&b[i]);
	for(int i=1;i<=n;i++)ord[i]=i;
	sort(ord+1,ord+1+n,[&](int i,int j){return a[i]>a[j];});
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=-inf;
	dp[0][0]=0;
	int sol=0,ptr=0;
	for(int i=1;i<=p+s;i++){
		for(int j=p;j>=0;j--){
			dp[i][j]=dp[i-1][j]+b[ord[i]];
			if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[ord[i]]);
		}
		if(i>=p){
			int need=p+s-i;
			int ans=dp[i][p];
			//printf("%i %i\n",i,dp[i][p]);
			for(int j=i+1;j<=n;j++)cnt[b[ord[j]]]++;
			for(int j=N-1;j>=0;j--){
				for(int k=0;k<cnt[j];k++){
					if(need>0){
						need--;
						ans+=j;
					}
				}
			}
			for(int j=i+1;j<=n;j++)cnt[b[ord[j]]]--;
			sol=max(sol,ans);
			if(sol==ans)ptr=i;
			//printf("%i\n",ans);
		}
	}
	printf("%i\n",sol);
	vector<int> A,B;
	vector<pair<int,int>> tmp;
	for(int i=ptr+1;i<=n;i++){
		tmp.push_back({b[ord[i]],ord[i]});
	}
	sort(tmp.rbegin(),tmp.rend());
	for(int i=0;i<p+s-ptr;i++)B.push_back(tmp[i].second);
	for(int i=p;ptr>0;ptr--){
		if(i==0||dp[ptr][i]==dp[ptr-1][i]+b[ord[ptr]]){
			B.push_back(ord[ptr]);
		}else{
			A.push_back(ord[ptr]);
			i--;
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i:A)printf("%i ",i);printf("\n");
	for(int i:B)printf("%i ",i);printf("\n");
	return 0;
}