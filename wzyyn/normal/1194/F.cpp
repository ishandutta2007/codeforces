#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
#define fi first
#define se second
#define uint unsigned
#define PB push_back
using namespace std;
const int mo=1000000007;
const int N=200005;
int fac[N],inv[N];
int n,ans;
ll T;
void init_fac(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
} 
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%lld",&n,&T);
	init_fac();
	int S=1,mx=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		T-=x;
		if (T<0) break;
		S=2ll*S%mo; mx++;
		for (bool fl=0;mx>=0&&mx>T;fl=1,mx--)
			if (fl==0) S=(S+mo-C(i-1,mx-1))%mo;
			else S=(S+mo-C(i,mx))%mo;
		ans=(ans+1ll*S*power((mo+1)/2,i))%mo;
	}
	printf("%d\n",ans);
}