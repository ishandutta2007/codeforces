// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;



const int N=1<<18;
int n;
struct car {
	ll t;
	int i;
	int x;
	car(ll t,int i,int x) : t(t), i(i), x(x) {}
	bool operator<(const car &o) const {
		if(t!=o.t) return t<o.t;
		if(i!=o.i) return i<o.i;
		if(x!=o.x) return x<o.x;
		return 0;
	}
};

bool rmq[N+N];
bool Q(int L,int R) {
	L+=N,R+=N;
	for(;;) {
		if(L&1 && rmq[L++]) return 1;
		if(!(R&1) && rmq[R--]) return 1;
		if(L>R) return 0;
		L>>=1,R>>=1;
	}
}
void SET(int i,bool x) {
	rmq[i+=N]=x;
	for(;(i>>=1)>0;) rmq[i]=rmq[i+i]|rmq[i+i+1];
}
queue<car> house[N];
set<car> busy;
ll tt=0;

void do_ride() {
	ll t; int a,b; scanf("%lld%d%d",&t,&a,&b);
	if(!Q(1,n)) tt=max(tt,busy.begin()->t);
	ll t0=t;
	t=max(t,tt);
	for(;busy.size() && busy.begin()->t <= t;) {
		house[busy.begin()->x].push(*busy.begin());
		SET(busy.begin()->x,1);
		busy.erase(busy.begin());
	}

	int L=0,R=n;
	for(;L!=R;) {
		int M=(L+R)>>1;
		if(Q(max(1,a-M),min(n,a+M))) R=M;
		else L=M+1;
	}

	int d=L;
	vector<int> poss;
	if(a-d>=1 && house[a-d].size()) poss.pb(a-d);
	if(a+d<=n && house[a+d].size() && d) poss.pb(a+d);
	assert(poss.size()==1u || poss.size()==2u);

	int u=poss[0];
	if(poss.size()==2u && house[poss[1]]<house[u]) u=poss[1];
	car c=house[u].front();
	house[u].pop();
	if(!house[u].size()) SET(u,0);
	printf("%d %lld\n",c.i,t+abs(u-a)-t0);
	c.x=b;
	c.t=t+abs(u-a)+abs(b-a);
	busy.insert(c);
}

void init(int k) {
	for(int j=1;j<=k;j++) {
		int x; scanf("%d",&x);
		car c(0LL,j,x);
		busy.insert(c);
	}
}





int32_t main() {
	int k,m;
	scanf("%d%d%d",&n,&k,&m);
	init(k);
	for(;m--;) {
		do_ride();
	}
}