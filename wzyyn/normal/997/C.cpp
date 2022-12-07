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
const int mo=998244353;
const int N=1000005;
int fac[N],inv[N],n;
void init(){
	inv[0]=inv[1]=fac[0]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int power(int x,ll y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int f(int x,int y){
	if (!x||!y){
		int p=x+y;
		return power(3,p+1ll*(n-p)*n);
	}
	return power(3,1+1ll*(n-x)*(n-y));
}
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	init();
	scanf("%d",&n);
	int ans=0;
	For(i,1,n){
		int val=2ll*C(n,i)*power(3,i+1ll*(n-i)*n)%mo;
		ans=(ans+(i&1?val:mo-val))%mo;
	}
	For(i,0,n-1){
		int v=power(3,i)%mo;
		int val=power(mo-v+1,n);
		int tmp=power(v,n)%mo;
		val=(val+mo-((n&1)?mo-tmp:tmp))%mo;
		val=3ll*C(n,i)*val%mo;
		ans=(ans+(i&1?val:mo-val))%mo;
	}
	/*For(i,0,n-1) For(j,0,n-1){
		int val=1ll*C(n,i)*C(n,j)%mo*power(3,1ll*i*j+1)%mo;
		ans=(ans+((i+j)&1?val:mo-val))%mo;
	}*/
	printf("%d\n",ans);
}
/*
ans=For(i,0,n) For(j,0,n)
		C(n,i)C(n,j)(-1)^(i+j)f(i,j)

i==0f(i,j)=3^i*3^(n-i)n
i>0j>0 
*/