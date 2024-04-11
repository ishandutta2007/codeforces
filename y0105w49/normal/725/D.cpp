#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// typedef __int128 INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const int inf=1e9+99;
#define fi first
#define se second
#define y1 arst

int main() {
	const int N=300<<10;
	int n; scanf("%d",&n);
	static ll t[N],w[N];
	for(int i=0;i<n;i++) scanf("%lld%lld",t+i,w+i);
	static pair<ll,ll> bel[N];
	int beln=0;
	for(int i=1;i<n;i++) bel[beln++]={t[i],w[i]};
	sort(bel,bel+beln);
	ll me=t[0];

	priority_queue<ll,vector<ll>,greater<ll> > abo;
	int be=n;
	for(;;) {
		for(;beln&&bel[beln-1].fi>me;) {
			beln--;
			abo.push(bel[beln].se-bel[beln].fi+1);
		}

		be=min(be,(int)abo.size()+1);

		if(be==1) break;
		assert(!abo.empty());
		ll req=abo.top(); abo.pop();
		if(req>me) break;
		me-=req;
	}
	printf("%d\n",be);
}