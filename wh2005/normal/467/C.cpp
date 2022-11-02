#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
ll a[5009],p[5009],sum[5009],f[5009][5009];
int main(){
	scanf("%d%d%d",&n,&m,&k);sum[0]=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	memset(f,-1,sizeof(f));
	memset(p,-1,sizeof(p));
	f[0][0]=0;p[0]=0;
	for(int i=m;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(p[j-1]==-1) continue;
			f[i][j]=max(f[i][j],p[j-1]+sum[i]-sum[i-m]);
		}
		for(int j=1;j<=k;j++) p[j]=max(p[j],f[i-m+1][j]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i][k]);
	printf("%lld\n",ans);
	return 0;
}