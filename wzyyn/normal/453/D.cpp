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
const int N=(1<<20)|5;
int n,cnt[N],tr[25];
ll A[N],B[N],T,mod;
ll mul(ll x,ll y){
	x%=mod; y%=mod;
	ll t=x*y-(ll)((long double)x/mod*y)*mod;
	return (t%mod+mod)%mod;
}
ll power(ll x,ll y){
	ll s=1;
	for (;y;y/=2,x=mul(x,x))
		if (y&1) s=mul(s,x);
	return s;
}
void DFT(ll *A,int n){
	for (int d=1;d<n;d<<=1)
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++){
				ll x=A[i+j],y=A[i+j+d];
				A[i+j]=(x+y)%mod;
				A[i+j+d]=(x+mod-y)%mod;
			}
}
int main(){
	scanf("%d%lld%lld",&n,&T,&mod); mod<<=n;
	For(i,0,(1<<n)-1) scanf("%lld",&A[i]);
	For(i,0,(1<<n)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,n) scanf("%d",&tr[i]);
	For(i,0,(1<<n)-1) B[i]=tr[cnt[i]];
	For(i,0,(1<<n)-1) A[i]%=mod,B[i]%=mod;
	DFT(A,1<<n); DFT(B,1<<n);
	//For(i,0,(1<<n)-1) cout<<A[i]<<' '<<B[i]<<endl;
	For(i,0,(1<<n)-1) A[i]=mul(A[i],power(B[i],T));
	DFT(A,1<<n);
	For(i,0,(1<<n)-1) printf("%lld\n",A[i]>>n);
}