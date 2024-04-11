using namespace std;
#include<bits/stdc++.h>
#define N 500001
#define ll long long
#define int ll
struct people{
	ll x,id;
	friend bool operator <(people a,people b) {
		return a.x<b.x;
	}
}xx[N];
ll n,A,cf,cm,m,cnt,d,tot,deb=0,ans[N],res,minx=1e18,S[N],B[N],fil;
ll  pd(ll x,ll &fd,ll &pos,ll wht) {
	ll l=1,r=tot,an=tot+1;
		while(l<=r) {
			ll mid=(l+r)>>1;
			if(xx[mid].x<=x) {
				an=mid;l=mid+1;
			}
			else r=mid-1;
		}
		fd=x*cm;
		pos=min(an,wht);
		return x*pos-S[pos];
}
ll get(ll x) {
	ll res=0,cost=m-B[tot-x+1];
	res=x*cf;
	if(cost<0) return -1;
	ll l=minx,r=A-1;
	ll fd,ih,kl;
	while(l<=r) {
		ll mid=(l+r)>>1;
		if(pd(mid,fd,kl,tot-x)<=cost) {
			l=mid+1;ih=fd;
		}
		else r=mid-1;
	}
	res+=ih;
	return res;
}
main() {
	cin>>n>>A>>cf>>cm>>m;minx=A;
	for(ll i=1;i<=n;i++) {
		ll hh;
		scanf("%lld",&hh);
		if(hh>=A){
			cnt++;ans[i]=hh;
			continue;
		}
		ans[i]=hh;
		xx[++tot].x=hh;
		xx[tot].id=i;
		minx=min(minx,hh);
	}
	sort(xx+1,xx+tot+1);
	ll dd=0;
	for(ll i=1;i<=tot;i++) {
		dd+=(A-xx[i].x);
	}
	if(dd<=m) {
		res=cf*n+cm*A;
		cout<<res<<endl;
		for(ll i=1;i<=n;i++) printf("%lld ",A);
		return 0;
	}
	for(ll i=1;i<=tot;i++) S[i]=S[i-1]+xx[i].x;
	for(ll i=tot;i>=0;i--) B[i]=(A-xx[i].x)+B[i+1];
	ll fg=0,it=0;
	for(ll i=tot;i>=0;i--) {
			ll wh=get(i);
			if(wh>=fg) {
				fg=wh;it=i;
			}
	}
	ll cost=0;
	for(ll i=tot;i>=(tot-it+1);i--) {
		ans[xx[i].id]=A;
		cost+=(A-xx[i].x);
		xx[i].x=A;
	}
	cost=m-cost;
	ll l=minx,r=A-1,pg=0,fd,pos,an;
	while(l<=r) {
		ll mid=(l+r)>>1;
		if(pd(mid,fd,pos,tot-it)<=cost) {
			pg=mid;l=mid+1;an=pos;
		}
		else r=mid-1;
	}
	for(ll i=1;i<=an;i++) {
		ans[xx[i].id]=max(ans[xx[i].id],pg);
	}
	fg+=cnt*cf;
	cout<<fg<<endl;
	for(ll i=1;i<=n;i++) printf("%lld ",ans[i]);
}