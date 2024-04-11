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
const int N=500005;
int fac[N],inv[N];
void init(){
	inv[0]=inv[1]=fac[0]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,2,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int main(){
	init();
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	For(i,1,n){
		int rem=n/i;
		if (rem>=k) ans=(ans+1ll*fac[rem-1]*inv[k-1]%mo*inv[rem-k])%mo;
	}
	printf("%d\n",ans);
}