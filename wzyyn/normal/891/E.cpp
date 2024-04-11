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
const int N=5005;
int n,k,a[N],f[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int F(int x){
	int ans=1;
	For(i,1,x) ans=1ll*ans*(k-i+1)%mo;
	ans=1ll*ans*power(n,mo-1-x)%mo;
	return ans;
}
int main(){
	f[0]=1;
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) Rep(j,i,1)
		f[j]=(f[j]+1ll*f[j-1]*a[i])%mo;
	int ans=1;
	For(i,1,n) ans=1ll*ans*a[i]%mo;
	For(i,0,n) ans=(ans+1ll*((n-i)&1?F(n-i):mo-F(n-i))*f[i])%mo;
	printf("%d\n",ans);
}