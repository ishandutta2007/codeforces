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
ll count(ll x,ll v){
	if (x<=v*2) return 0;
	ll s1=1,s2=0,p1=x,p2=x-1,ans=0;
	for (;p2>=v*2;p1/=2,p2=p1-1){
		if (p2==v*2) return s1+ans;
		ans+=s1+s2; p1&1?s1=s1*2+s2:s2=s2*2+s1;
	}
	return ans;
}
ll solve(ll l,ll r,ll v,ll k){
	ll mid=(l+r)/2;
	if (k==1) return mid;
	ll v1=count(mid-l,v);
	ll v2=count(r-mid,v+1);
	if (k>v1+v2+1) return solve(mid+1,r,v,k-v1-1);
	return solve(l,mid-1,v,k-v2-1);
}
int main(){
	ll n,k; 
	scanf("%lld%lld",&n,&k);
	if (k==1) return puts("1"),0;
	if (k==2) return printf("%lld\n",n),0;
	n-=2; k-=2;
	ll l=0,r=n/2+1,ans=-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (count(n,mid)>=k)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	//cout<<ans<<endl;
	printf("%lld\n",solve(2,n+1,ans,k));
}