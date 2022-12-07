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
ll n;
ll G(ll x){
	ll v=0;
	for (;x;v+=x%10,x/=10);
	return v;
}
ll F(ll x){
	static ll a[20];
	a[0]=0;
	ll ans=G(x);
	for (;x;a[++*a]=x%10,x/=10);
	For(i,1,*a){
		ll v=0,vv=1;
		For(j,1,i-1) vv*=10;
		For(j,i+1,*a) v+=a[j];
		For(j,0,a[i]-1){
			ans+=(v+j)*vv;
			ans+=vv/10*(i-1)*45;
			//cout<<i<<' '<<j<<' '<<ans<<endl;
		}
	}
	return ans;
}
int main(){
	scanf("%lld",&n);
	ll l=1,r=3e16,p=0;
	while (l<=r){
		ll mid=(l+r)/2;
		if (F(mid)<=n) p=mid,l=mid+1;
		else r=mid-1;
	}
	l=1,r=p;
	ll v=F(p);
	for (;v!=n;)
		if (v<n) v+=G(++r);
		else v-=G(l++);
	printf("%lld %lld\n",l,r);
}