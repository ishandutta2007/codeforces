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






const int N=1<<17;
int n,m;
ll rmq[N+N];
int a[N];
pair<int,int> b[N];
map<int,int> mm;
map<int,int> rr;

void inc(int i,int x) {
	rr[i] += x;
	if(!rr[i]) rr.erase(i);
	i+=N;
	for(;i>0;) rmq[i]+=x, i>>=1;
}
void spend(int i,int x) {
	for(;x;) {
		auto it=rr.upper_bound(i);
		assert(it!=rr.begin());
		--it;
		int d=min(x,it->se);
		inc(it->fi,-d);
		x-=d;
	}
}
ll Q(int L,int R) {
	L+=N,R+=N;
	ll Z=0;
	for(;;) {
		if(L&1) Z+=rmq[L++];
		if(!(R&1)) Z+=rmq[R--];
		if(L>R) return Z;
		L>>=1,R>>=1;
	}
}



int32_t main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int j=1;j<=m;j++) scanf("%d",&b[j].se);
	for(int j=1;j<=m;j++) scanf("%d",&b[j].fi);

	for(int i=1;i<=n;i++) {
		mm[a[i]]=i;
		for(;;) {
			auto it=mm.lower_bound(a[i]);
			if(it==mm.begin()) break;
			--it;
			mm.erase(it);
		}
	}

	for(int i=1;i<=n;i++) inc(i,a[i]);

	sort(b+1,b+1+m);
	int Z=0;
	for(int j=1;j<=m;j++) {
		auto it=mm.lower_bound(b[j].se);
		if(it==mm.end()) continue;
		int i=it->se;
		if(Q(1,i) >= b[j].fi) ++Z, spend(i,b[j].fi);
	}
	printf("%d\n",Z);
}