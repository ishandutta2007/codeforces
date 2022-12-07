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
const int N=100005;
int n,a[N],b[N];
ll k,l[N],r[N];
ll count(ll x){
	ll sum=0;
	For(i,1,n){
		int pl=1,pr=a[i],ans=0;
		while (pl<=pr){
			int mid=(pl+pr)/2;
			ll slop=a[i]-3ll*mid*mid+3ll*mid-1;
			if (slop>x) ans=mid,pl=mid+1;
			else pr=mid-1;
		}
		l[i]=r[i]=ans; sum+=ans;
		if ((++ans)>a[i]) continue;
		if (a[i]-3ll*ans*ans+3ll*ans-1==x) ++r[i];
	}
	return sum;
}
int main(){
	scanf("%d%lld",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	ll l=-(1ll<<62),r=1ll<<62,ans=-l-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (count(mid)<=k)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	//cout<<ans<<' '<<count(ans)<<endl;
	count(ans);
	For(i,1,n) b[i]=::l[i],k-=::l[i];
	For(i,1,n) if (::l[i]!=::r[i]&&k) ++b[i],--k;
	For(i,1,n) printf("%d ",b[i]);
	puts("");
}
/*
xai-x^3
ai-3x^2+3x-1
*/