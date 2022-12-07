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
int n,fa[N],ans;
int b[N],f[N];
ll a[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,2,n) scanf("%d",&fa[i]);
	Rep(i,n,1) a[fa[i]]+=a[i];
	For(i,1,n){
		ll tmp=a[1]/gcd(a[1],a[i]);
		if (tmp<=n) b[tmp]++;
	}
	f[1]=1;
	Rep(i,n,1) For(j,2,n/i) b[i*j]+=b[i];
	For(i,1,n) if (b[i]==i)
		For(j,2,n/i) f[i*j]=(f[i*j]+f[i])%mo;
	For(i,1,n) if (b[i]==i) ans=(ans+f[i])%mo;
	printf("%d\n",ans);
}