#include<bits/stdc++.h>

using namespace std;

const int N=2000005;
const int mo=1000000007;
int fac[N],inv[N],IP2[N];
void init(){
	fac[0]=inv[0]=inv[1]=IP2[0]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	for (int i=1;i<N;i++)
		IP2[i]=1ll*IP2[i-1]*(mo+1)/2%mo;
}
int Path(int sx,int sy,int tx,int ty){
	int x=tx-sx,y=ty-sy;
	return 1ll*IP2[x]*fac[x]%mo*inv[y]%mo*inv[x-y]%mo;
}
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if (m==n) printf("%d\n",1ll*n*k%mo);
	else{
		int ans=0;
		for (int i=1;i<=m;i++)
			ans=(ans+1ll*Path(i+1,i,n,m)*i%mo*k)%mo;
		ans=1ll*ans*(mo+1)/2%mo;
		printf("%d\n",ans);
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}