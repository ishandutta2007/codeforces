#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int mo=1000000007;
const int N=3000005;

int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int a[N],b[N],n;
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=3*n;i++)
		a[i]=1ll*fac[3*n]*inv[i]%mo*inv[3*n-i]%mo;
	for (int i=0;i<3*n;i++){
		b[i]=1ll*a[i+1]*(mo+1)/3%mo;
		a[i+1]=(a[i+1]+mo-3ll*b[i]%mo)%mo;
		a[i+2]=(a[i+2]+mo-3ll*b[i]%mo)%mo;
		a[i+3]=(a[i+3]+mo-1ll*b[i]%mo)%mo;
		//cout<<b[i]<<endl;
	}
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,ans=0;
		scanf("%d",&x);
		ans=(b[x]+3ll*b[x-1])%mo;
		if (x>=2) ans=(ans+3ll*b[x-2])%mo;
		if (x>=3) ans=(ans+1ll*b[x-3])%mo;
		printf("%d\n",ans);
	}
}