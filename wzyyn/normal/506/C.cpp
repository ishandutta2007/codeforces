#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int n,m,k,p;
ll h[N],a[N],val[N],ddl[N];
priority_queue<pll > Q;
bool check(ll v){
	ll ysgh=0;
	For(i,1,n){
		if (v-1ll*m*a[i]<h[i]){
			ll val=h[i]-(v-1ll*m*a[i]);
			ysgh+=val/p+(val%p!=0);
		}
	}
	if (ysgh>m*k) return 0;
	while (!Q.empty()) Q.pop();
	For(i,1,n){
		ddl[i]=(val[i]=v)/a[i];
		Q.push(pll(-ddl[i],i));
	}
	int rem=1;
	For(i,0,m-1){
		if (Q.top().fi>-i) return 0;
		for (;Q.top().fi==-i&&rem;){
			int id=Q.top().se;
			Q.pop(); --rem;
			val[id]+=p;
			ddl[id]=val[id]/a[id];
			Q.push(pll(-ddl[id],id));
		}
		if (!rem) return 0;
		rem+=k;
	}
	return 1;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	For(i,1,n) scanf("%lld%lld",&h[i],&a[i]);
	ll l=0,r=1ll<<60,ans=0;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}