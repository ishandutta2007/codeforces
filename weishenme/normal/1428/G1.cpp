#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
ll f[N],g[N],a[N],ans;
int n,F1,F2,F3,F4,F5,F6,k;
inline void upd(ll &x,ll y){
	if (x<y)x=y;
}
inline int calc(int y,int x){
	if (x*9<y)return -1e9;
	if (y%3==0)return y/3;
	if ((x-1)*9>=y)return y/3;
	return (y/9)*3;
}
int main(){
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&F1,&F2,&F3,&F4,&F5,&F6);
	scanf("%d",&k);scanf("%d",&k);
	for (int i=0;i<=9;i++)f[i]=(ll)calc(i,n)*F6;
	for (int i=0;i<N;i++)g[i]=-1e18;
	for (int i=0;i<=99;i++)a[i]=(ll)calc(i,n)*F5;
	for (int i=0;i<=9;i++){
		const int x=i*10;
		for (int j=0;j<=99-x;j++)
			upd(g[x+j],f[i]+a[j]);
	}
	for (int i=0;i<=99;i++)f[i]=g[i],g[i]=-1e18;
	for (int i=0;i<=999;i++)a[i]=(ll)calc(i,n)*F4;
	for (int i=0;i<=99;i++){
		const int x=i*10;
		for (int j=0;j<=999-x;j++)
			upd(g[x+j],f[i]+a[j]);
	}
	for (int i=0;i<=999;i++)f[i]=g[i],g[i]=-1e18;
	for (int i=0;i<=9999;i++)a[i]=(ll)calc(i,n)*F3;
	for (int i=0;i<=999;i++){
		const int x=i*10;
		for (int j=0;j<=9999-x;j++)
			upd(g[x+j],f[i]+a[j]);
	}
	for (int i=0;i<=9999;i++)f[i]=g[i],g[i]=-1e18;
	for (int i=0;i<=99999;i++)a[i]=(ll)calc(i,n)*F2;
	for (int i=0;i<=9999;i++){
		const int x=i*10;
		for (int j=0;j<=99999-x;j++)
			upd(g[x+j],f[i]+a[j]);
	}
	for (int i=0;i<=99999;i++)f[i]=g[i],g[i]=-1e18;
	for (int i=0;i<=k;i++)a[i]=(ll)calc(i,n)*F1;
	for (int i=0;i<=k/10;i++)upd(ans,a[k-i*10]+f[i]);
	printf("%lld\n",ans);
}