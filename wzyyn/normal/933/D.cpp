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
const int mo=1000000007;
int ans;
ll n;
int S2(ll k){
	k%=mo;
	return 1ll*k*(k+1)/2%mo;
}
int S3(ll k){
	k%=mo;
	return 1ll*k*(k+1)%mo*(2*k+1)%mo*(mo+1)/6%mo;
}
int main(){
	scanf("%lld",&n);
	int p=1,j=0;
	for (;1ll*p*p<=n;++p);
	int v0=1,v1=0,v2=0,v3=0;
	Rep(i,p-1,1){
		for (;1ll*i*i+1ll*(j+1)*(j+1)<=n;){
			++j;
			int v=1ll*j*j%mo;
			v0=(v0+1)%mo;
			v1=(v1+v)%mo;
			v2=(v2+1ll*v*v)%mo;
			v3=(v3+1ll*v*v%mo*v)%mo;
		}
		ans=(ans+2ll*(j+1)*(S3(n)+S2(n)))%mo;
		int v=1ll*i*i%mo;
		int nv0=v0;
		int nv1=(1ll*v0*v+1ll*v1*1)%mo;
		int nv2=(1ll*v0*v%mo*v+2ll*v1*v+1ll*v2*1)%mo;
		int nv3=(1ll*v0*v%mo*v%mo*v+3ll*v1*v%mo*v+3ll*v2*v+v3)%mo;
		ans=(ans+1ll*(1+(mo+1)/3)*nv3)%mo;
		ans=(ans+1ll*(2*n%mo+2+2*(mo+1)/3)*nv1)%mo;
		ans=(ans+mo-1ll*(2*n%mo+4)*nv2%mo)%mo;
	}
	ans=(ans+1ll*(mo+1)/2*(S3(n)+S2(n)))%mo;
	printf("%d\n",ans);
}
/*
sigma 2(i-v+1)(i+v)
sigma 2i^2-2v^2+2i+2v
*/