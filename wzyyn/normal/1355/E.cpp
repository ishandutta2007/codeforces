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
int n,A,R,M,a[N];
ll F(int p){
	ll s0=0,s1=0;
	For(i,1,n)
		if (a[i]<p) s0+=p-a[i];
		else s1+=a[i]-p;
	ll ans=s0*A+s1*R;
	if (M<A+R) ans-=min(s0,s1)*(A+R-M);
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&A,&R,&M);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=0,r=1e9;
	while (l+10<=r){
		int mid=(l+r)/2;
		if (F(mid)<F(mid+1)) r=mid+1;
		else l=mid;
	}
	ll ans=1ll<<60;
	For(i,l,r) ans=min(ans,F(i));
	printf("%lld\n",ans);
}