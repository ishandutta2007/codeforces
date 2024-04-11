#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

const int N=100005;

int n,m,k,a[N],l;
pi b[N];

struct node{
	ll ans;
	vector<pi> a,b;
	node(){
		ans=0ll;
		a.clear();
		b.clear();
	}
	void ins(pi u){
		if(!b.size())b.pb(u);else{
			auto&v=*b.rbegin();
			if(v.fi==u.fi)v.se+=u.se;else b.pb(u);
		}
		ans+=u.se;
		while(b.size()){
			auto&v=*b.rbegin();
			ans-=v.se/k*k,v.se%=k;
			if(v.se)break;b.pop_back();
		}
	}
}A,R;

node operator+(node x,node y){
	ll la=x.ans;
	if(y.ans<=2*n){
		for(auto cur:y.b)x.ins(cur);
	}else{
		ll ext=y.ans;
		for(auto cur:y.a)x.ins(cur),ext-=cur.se;
		x.b=y.b;x.ans+=ext;
	}
	ll ra=x.ans;
	if(la<=2*n&&2*n<ra)x.a=x.b;
	return x;
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]!=b[l].fi)b[++l]={a[i],1};else b[l].se++;
	if(l==1)printf("%d\n",(long long)n*m%k),exit(0);
	for(int i=1;i<=l;i++)A.ins(b[i]);
	while(m){
		if(m&1)R=R+A;
		A=A+A;m>>=1;
	}
	printf("%lld\n",R.ans);
	return 0;
}