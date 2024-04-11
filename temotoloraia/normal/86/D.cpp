#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
ll s,n,t,cnt;
ll ans[200001];
ll a[200001];
ll sixsh[1000001];
struct querry{
	ll l,r,k;
};
vector<querry> q;
bool comp(querry u,querry v){
	ll l1,r1,l2,r2;
	l1=u.l;
	r1=u.r;
	l2=v.l;
	r2=v.r;
	ll p1=(l1+s-1)/s;
	ll p2=(l2+s-1)/s;
	if(p1<p2)
	   return 1;
	else{
		if(p1==p2){
			if(r1<r2)
			   return 1;
			else
			   return 0;
		}
		else
		   return 0;
	}
}
ll add(ll cnt,ll i){
	cnt-=sixsh[a[i]]*sixsh[a[i]]*a[i];
	sixsh[a[i]]++;
	cnt+=sixsh[a[i]]*sixsh[a[i]]*a[i];
	return cnt;
}
ll del(ll cnt,ll i){
	cnt-=sixsh[a[i]]*sixsh[a[i]]*a[i];
	sixsh[a[i]]--;
	cnt+=sixsh[a[i]]*sixsh[a[i]]*a[i];
	return cnt;
}
ll update(ll cnt,ll mol,ll mor,ll l,ll r){
	while(mol>l){
		mol--;
		cnt=add(cnt,mol);
	}
	while(mol<l){
		cnt=del(cnt,mol);
		mol++;
	}
	while(mor<r){
		mor++;
		cnt=add(cnt,mor);
	}
	while(mor>r){
		cnt=del(cnt,mor);
		mor--;
	}
	return cnt;
}
int main(){
	cin>>n>>t;
	for(ll k=1;k<=n;k++)
	    scanf("%lld",&a[k]);
	for(ll k=1;k<=t;k++){
		ll l,r;
		scanf("%lld",&l);
		scanf("%lld",&r);
		q.push_back({l,r,k});
	}
	s=sqrt((4*n*n)/t);
	if(s==0)
	   s=1;
	sort(q.begin(),q.end(),comp);
	ll mol,mor;
	mol=1,mor=0;
	cnt=0;
	for(ll k=0;k<q.size();k++){
		ll l,r;
		l=q[k].l;
		r=q[k].r;
		cnt=update(cnt,mol,mor,l,r);
		mol=l;
		mor=r;
		ans[q[k].k]=cnt;
	}
	for(ll k=1;k<=t;k++)
	    printf("%llu\n",ans[k]);
    return 0;
}