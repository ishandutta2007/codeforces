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
const int N=1000005;
int k,n,ans;
int fac[N],inv[N];
int power(int x,int y){
	int s=1;
	if (y<0) y+=mo-1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int F(int l1,int l2){
	if (l1>k) return 0;
	if (l1+l2<=n+l2){
		int ans=power(k,n-l1-1);
		ans=1ll*ans*fac[k]%mo*inv[k-l2]%mo*l2%mo;
		ans=1ll*ans*fac[k]%mo*inv[k-l1]%mo;
		return ans;
	}
	else{
		int ans=1;
		ans=1ll*ans*fac[k]%mo*inv[k-l1]%mo;
		ans=1ll*ans*(n+l2-l1)%mo*fac[k-l1+n-1]%mo*inv[k-l2]%mo;
		return ans;
	}
}
int main(){
	scanf("%d%d",&k,&n);
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,N-1) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	For(ex,1,k) ans=(1ll*ans+F(ex,ex)+F(ex+1,ex))%mo;
	//cout<<F(1,1)<<' '<<F(2,1)<<' '<<F(2,2)<<' '<<F(3,2)<<endl;
	printf("%d\n",ans);
}
/*
1-ex+1 ex+1-t
*/