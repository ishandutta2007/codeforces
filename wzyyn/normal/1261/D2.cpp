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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=500005;
const int mo=998244353;
int fac[N],inv[N],P[N];
int n,k,m,h[N],ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	fac[0]=inv[0]=inv[1]=P[0]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) P[i]=2ll*P[i-1]%mo;
}
int C(int x,int y){
	if (y<0||x<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&h[i]); h[n+1]=h[1];
	For(i,1,n) if (h[i]!=h[i+1]) m++;
	For(i,0,m){
		int S=power(2,i);
		if (i%2==0) S=(S+mo-C(i,i/2))%mo;
		ans=(ans+1ll*S*C(m,i)%mo*power(max(0,k-2),m-i))%mo;
		//printf("%d %d %d\n",i,S,ans);
	}
	ans=1ll*ans*power(k,n-m)%mo;
	ans=1ll*ans*(mo+1)/2%mo;
	printf("%d\n",ans);
}