#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005,mod=998244353;
int n,k,T,ans;
int a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int flg=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=n-k+1;i<=n;i++)
			if(a[i]>0)
				flg=1;
		for(int i=1;i<=n-k;i++)
			if(a[i]!=-1&&a[i]+k>=i+k)
				flg=1;
		if(flg){
			puts("0");
			continue;
		}
		ans=1;
		for(int i=1;i<=n-k;i++){
			if(a[i]==-1)
				ans=1ll*ans*(i+k)%mod;
			if(a[i]==0)
				ans=1ll*ans*(k+1)%mod;
		}
		for(int i=1;i<=k;i++)
			ans=1ll*ans*i%mod;
		printf("%d\n",ans);
	}
	return 0;
}