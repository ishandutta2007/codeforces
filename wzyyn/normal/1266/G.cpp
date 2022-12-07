#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1000005;
const int mo=998244353;
int n,fac[N],inv[N],C[N*2];
int main(){
	scanf("%d",&n);
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,n) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mo;
	C[0]=n;
	For(i,1,n-1) C[i]=1ll*fac[n]*inv[n-i+1]%mo*(1ll*(n-i)*(n-i)%mo+1)%mo;
	For(i,0,n-1) C[i+n]=(fac[n]+mo-C[i])%mo;
	int ans=1ll*fac[n]*n%mo;
	ans=1ll*ans*(ans+1)/2%mo;
	For(i,0,2*n-1) ans=(ans+mo-1ll*i*C[i]%mo)%mo;
	printf("%d\n",ans);
}
/*
1 2 2 1

*/