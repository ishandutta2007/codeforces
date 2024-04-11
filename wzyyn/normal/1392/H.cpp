#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=998244353;
const int N=5000005;
int fac[N],inv[N];
int f[N],p[N],n,m,ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int IC(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*inv[x]*fac[y]%mo*fac[x-y]%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	For(i,0,n) p[i]=1ll*IC(n+m,n)*C(n-i+m-1,n-i)%mo;
	int sum=0;
	For(i,1,n){
		int k=1,b=0;
		b=(b+mo-1ll*sum*IC(i+m,m)%mo)%mo;
		//For(l2,1,i) b=(b+mo-1ll*C(i-l2+m-1,m-1)*IC(i+m,m)%mo*f[i-l2]%mo)%mo;
		k=(k+mo-1ll*C(i+m-1,m-1)*IC(i+m,m)%mo)%mo;
		b=(b+mo-1ll*power(m+1,mo-2)*n%mo-1)%mo;
		f[i]=1ll*(mo-b)*power(k,mo-2)%mo;
		sum=(sum+1ll*C(i+m-1,m-1)*f[i])%mo;
		//cout<<i<<' '<<f[i]<<endl; 
	}
	cout<<f[n]<<endl;
}
/*
1 1:0.5
2 1:1
3 1:1.5
*/