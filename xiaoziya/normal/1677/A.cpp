#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,T;
long long ans;
int p[maxn],tot[maxn][maxn],sum[maxn][maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		/*for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(p[i]>p[j])
					sum[i]++;
		for(int i=n;i>=1;i--)
			sum[i]+=sum[i+1];
		for(int i=1;i<=n;i++){
			tot[i][i]=0;
			for(int j=i-1;j>=1;j--)
				tot[i][j]=tot[i][j+1]+(p[j]>p[i]);
		}*/
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				sum[i][j]=sum[i][j+1];
				if(p[i]>p[j])
					sum[i][j]++;
			}
			for(int j=1;j<=i;j++){
				tot[i][j]=tot[i][j-1];
				if(p[i]>p[j])
					tot[i][j]++;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<n;j++)
				ans+=1ll*sum[i][j+1]*tot[j][i-1];
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				sum[i][j]=tot[i][j]=0;
	}
	return 0;
}