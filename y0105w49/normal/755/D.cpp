#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef long long ll;
#define fi first
#define se second
#define pb push_back


const int N=1<<20;
int rmq[N+N];
void INC(int x) {
	x+=N;
	for(;x;) ++rmq[x], x>>=1;
}
int RG(int L,int R) {
	assert(L<=R);
	L+=N, R+=N;
	int Z=0;
	for(;;) {
		if(L&1) Z+=rmq[L++];
		if(!(R&1)) Z+=rmq[R--];
		if(L>R) return Z;
		L>>=1, R>>=1;
	}
}



int main() {
	int n,k; scanf("%d%d",&n,&k);
	if(k+k>n) k=n-k;
	int x=1;
	ll W=1;
	for(int i=1;i<=n;i++) {
		int L=x+1;
		int R=x+k-1;
		int Z=0;
		if(L>n) L-=n, R-=n;
		if(R>n) Z+=2*RG(L,n), L=1, R-=n;
		Z+=2*RG(L,R);
		Z+=1;
		INC(x);
		x+=k;
		if(x>n) x-=n, --Z;
		if(x==1) ++Z;

		W+=Z;
		printf("%lld%c",W," \n"[i==n]);
	}
}