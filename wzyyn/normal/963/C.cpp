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
const int N=200005;
map<ll,ll> mp1,mp2;
int n;
ll G,all;
ll a[N],b[N],c[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		mp1[a[i]]+=c[i]; 
		mp2[b[i]]+=c[i];
		all+=c[i];
		G=gcd(G,c[i]);
	}
	For(i,1,n)
		if (fabs((long double)mp1[a[i]]/all-(long double)c[i]/mp2[b[i]])>1e-12)
			return puts("0"),0;
	int ans=0;
	for (int i=1;1ll*i*i<=G;i++)
		if (G%i==0) ans+=1+(1ll*i*i!=G);
	printf("%d\n",ans);
}