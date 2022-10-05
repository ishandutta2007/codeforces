#include<bits/stdc++.h>
using namespace std;
#define INF 10000000000000000ll
int n;
long long a[510000];
long long b[510000],c[510000];
int aa[510000];
int dp[510000];
int tot;
int maxx[510000];
int mx[510000];
int main(){
	int _;
	cin>>_;
	while(_--){
		a[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)a[i]+=a[i-1];
		for(int i=0;i<=n;i++)b[i]=a[i];
		sort(b,b+n+1);
		tot=1;
		c[1]=b[0];
		for(int i=1;i<=n;i++)if(b[i]!=b[i-1])c[++tot]=b[i];
		for(int i=0;i<=n;i++){
			int l=1,r=tot;
			for(;l<r;){
				int md=(l+r)/2;
				if(c[md]>=a[i])r=md;
				else l=md+1;
			}
			aa[i]=l;
		}
		int tm=0;
		dp[0]=0;
		for(int i=1;i<=tot;i++)mx[i]=maxx[i]=-10000000;
		mx[aa[0]]=max(mx[aa[0]],dp[0]);
		for(int j=aa[0];j<=tot;j+=(j&(-j)))maxx[j]=max(maxx[j],dp[0]);
		for(int i=1;i<=n;i++){
			dp[i]=max(tm-i,mx[aa[i]]);
			for(int j=aa[i]-1;j;j-=(j&(-j)))if(maxx[j]+i>dp[i])dp[i]=maxx[j]+i;
			tm=max(tm,dp[i]+i);
			mx[aa[i]]=max(mx[aa[i]],dp[i]);
		    for(int j=aa[i];j<=tot;j+=(j&(-j)))maxx[j]=max(maxx[j],dp[i]-i);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}