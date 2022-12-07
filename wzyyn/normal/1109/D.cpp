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
const int mo=1000000007;
int fac[N],inv[N],n,m,ans;
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
}
int power(int x,int y){
	int s=1;
	if (y<0) y+=mo-1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	For(i,2,n){
		int val=fac[i-2];
		val=1ll*val*C(m-1,i-2)%mo*C(n-2,i-2)%mo;
		val=1ll*val*i%mo*power(n,n-i-1)%mo;
		val=1ll*val*power(m,n-i)%mo;
		//cout<<i<<' '<<val<<endl;
		ans=(ans+val)%mo;
	}
	printf("%d\n",ans);
}