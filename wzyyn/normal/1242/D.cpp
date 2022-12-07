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
ll n,sz,k;
ll getban(ll id){
	if (id==0) return 1ll*k*(k+1)/2;
	ll v=getban(id/k),sub=id%k;
	ll vl=(id/k)*sz+sub*k+1,vr=vl+k;
	//printf("%lld %lld\n",vl,vr);
	return 1ll*(vl+vr)*(vr-vl+1)/2-max(min(vr,v),vl);
}
void solve(){
	scanf("%lld%lld",&n,&k);
	sz=1ll*k*k+1;
	ll be=(n-1)/sz;
	ll ban=getban(be);
	if (ban!=n){
		ll pre=(n-1)/sz+(ban<=n);
		ll ans=n+(n-pre-1)/k-pre;
		printf("%lld\n",ans);
	}
	else{
		ll Ban=getban(be/k),sub=be%k;
		ll vl=(be/k)*sz+sub*k+1,vr=vl+k;
		ll v=(vr<=Ban?vr-1:vr);
		ll pre=(v-1)/sz+(Ban<=v);
		ll ans=v+(v-pre-1)/k-pre+1;
		printf("%lld\n",ans);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}