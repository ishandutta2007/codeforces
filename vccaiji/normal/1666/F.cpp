#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[5005];
int f[5005][5005];
int di[5005],id[5005];
int b[5005];
int yy[5005];
int df[5005];
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int main(){
	di[0]=1;
	for(int i=1;i<=5000;++i)di[i]=1ll*di[i-1]*i%mod;
	id[5000]=powdv(di[5000],mod-2);
	for(int i=4999;i>=0;--i)id[i]=1ll*id[i+1]*(i+1)%mod;
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n; 
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)
			f[i][j]=0;
		for(int i=0;i<=n;++i)b[i]=0;
		for(int i=1;i<=n;++i)++b[a[i]];
		int wz=1;
		for(int i=1;i<=n;++i){
			while(wz<=n&&a[wz]<a[i])++wz;
			f[1][i]=wz-1;
		}
		for(int i=n;i>=1;--i){
			if(i==n)yy[i]=n;
			else if(a[i]<a[i+1])yy[i]=i;
			else yy[i]=yy[i+1];
		}
		int he;
		for(int i=1;i<n/2;++i){
			if(i>1){
				f[i][n+1]=he;
				for(int j=n;j>=1;--j){
					f[i][j]=(f[i][j+1]-df[j])%mod;
					df[j]=0;
				}
			}
			int wz=1;
			he=0;
			for(int j=1;j<=n;++j)df[j]=0;
			for(int j=1;j<=n;++j){
				while(wz<=n&&a[wz]<a[j])++wz;
				int ss=1ll*max(wz-2*i,0)*f[i][j]%mod;
				df[yy[j]]=(df[yy[j]]+ss)%mod;
				he=(he+ss)%mod;
			}
		}
		if(n>2){
			f[n/2][n+1]=he;
			for(int j=n;j>=1;--j){
				f[n/2][j]=(f[n/2][j+1]-df[j])%mod;
				df[j]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)ans=(ans+f[n/2][i])%mod;
		for(int i=0;i<=n;++i)ans=1ll*ans*id[b[i]]%mod;
		ans=(ans+mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}