#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);


const int N=1<<17;
struct dat {
	int npop,npush;
	int x;
} rmq[N+N];

dat agg(const dat &L,const dat &R) {
	dat Z;
	int midpush = L.npush;
	int midpop = R.npop;
	Z.npop = L.npop;
	Z.npush = R.npush;
	if(midpush > midpop) Z.npush += midpush-midpop;
	if(midpop > midpush) Z.npop += midpop-midpush;
	return Z;
}

int Q(int L,int R) {
	int LL=L,RR=R;
	L+=N, R+=N;
	vector<int> lef,rig;
	for(;;) {
		if(L&1) lef.pb(L++);
		if(!(R&1)) rig.pb(R--);
		if(L>R) break;
		L>>=1, R>>=1;
	}

	reverse(rig.begin(),rig.end());
	for(int i:rig) lef.pb(i);
	reverse(lef.begin(),lef.end());

	int need=1;
	int fd=-1;
	for(int i:lef) {
		if(need<=rmq[i].npush) {
			fd=i;
			break;
		}
		need-=rmq[i].npush-rmq[i].npop;
	}
	if(fd==-1) return -1;
	for(;;) {
		if(fd>=N) {
			assert(need==1);
			assert(rmq[fd].npush==1);
			return rmq[fd].x;
		}

		L=fd+fd;
		R=L+1;
		if(need<=rmq[R].npush) fd=R;
		else {
			need-=rmq[R].npush-rmq[R].npop;
			fd=L;
		}
	}
}

int main() {
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int p,t,x; scanf("%d%d",&p,&t); --p;
		p+=N;
		if(t) scanf("%d",&x);
		if(t) rmq[p].npush=1, rmq[p].x=x;
		else rmq[p].npop=1;
		for(;;) {
			p>>=1;
			if(!p) break;
			rmq[p]=agg(rmq[p+p],rmq[p+p+1]);
		}

		printf("%d\n",Q(0,n-1));
	}
}