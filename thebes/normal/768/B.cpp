#include <bits/stdc++.h>
#define al(x) (x).begin(),(x).end()
#define gc(x) cin.get(x)
#define gl(x) getline(cin,x)
#define lb(x) ((x)&(-x))
#define sz(x) (int)(x.size())
#define sp ' '
#define nl '\n'
#define fi first
#define se second
using namespace std;
template<class...A>void sc(A&...a){((cin>>a),...);}
template<class...A>void pr(A...a){((cout<<a),...);}
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int,int> pi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,l,r;

ll hb(ll x){
	ll ret=2;
	while(x>1){
		x>>=1;
		ret<<=1;
	}
	return ret-1;
}

ll ans=0;

void go(ll tl=1,ll tr=hb(n),ll val=n){
	//pr("current is ",tl,sp,tr,sp,val,nl);
	if(r<tl||l>tr)return;
	if(tl==tr){
		if(val==1ll)ans++;
		return;
	}
	ll nw=val>>1,bb=hb(nw);
	go(tl,tl+bb-1,nw);
	go(tl+bb,tl+bb,val&1);
	go(tl+bb+1,tr,nw);
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	sc(n,l,r);go();
	pr(ans,nl);
}