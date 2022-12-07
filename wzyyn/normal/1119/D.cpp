#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005;
int n,Q,tot;
ll a[N],ans[N];
pll q[N*2];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	For(i,2,n) q[++tot]=pll(a[i]-a[i-1]-1,0);
	scanf("%d",&Q);
	For(i,1,Q){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		q[++tot]=pll(r-l,i);
		ans[i]=a[n]-a[1]+r-l+1;
	}
	sort(q+1,q+tot+1);
	ll s1=a[n]-a[1]-(n-1),s2=n-1;
	For(i,1,tot)
		if (q[i].se==0)
			s1-=q[i].fi,s2--;
		else ans[q[i].se]-=s1-s2*q[i].fi;
	For(i,1,Q) printf("%lld ",ans[i]);
}