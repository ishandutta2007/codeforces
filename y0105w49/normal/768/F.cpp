#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-7;
const int inf=1e9+99;
const ll linf=1e18+88;

const int P=1e9+7;
int powq(int x,int e) {
	if(!e) return 1;
	if(e&1) return int(1LL*x*powq(x,e-1)%P);
	x=powq(x,e>>1);
	return int(1LL*x*x%P);
}
int inv(int x) { return powq(x,P-2); }

const int N=200<<10;
int F[N],iF[N];
int C(int n,int k) {
	if(k>n) return 0;
	return int(1LL*F[n]*iF[k]%P*iF[n-k]%P);
}

int assign(int amt,int len) {
	amt-=len;
	if(amt<0) return 0;
	return C(amt+len-1,len-1);
}

int32_t main() {
	F[0]=1;
	for(int x=1;x<N;x++) F[x]=int(1LL*F[x-1]*x%P);
	iF[N-1]=inv(F[N-1]);
	for(int x=N-1;--x>=0;) iF[x]=int(1LL*iF[x+1]*(x+1)%P);

	int f,w,h; cin>>f>>w>>h;
	if(!h || !w) {
		cout<<1<<endl;
		return 0;
	}
	if(w<=h) {
		cout<<0<<endl;
		return 0;
	}
	if(!f) {
		cout<<1<<endl;
		return 0;
	}

	ll tot=0;
	for(int len=1;len<N-3;len++) {
		ll WF = 1LL*assign(w,len)*assign(f,len);
		ll FW = WF;
		ll WFW = 1LL*assign(w,len+1)*assign(f,len);
		ll FWF = 1LL*assign(w,len)*assign(f,len+1);
		tot += WF+FW+WFW+FWF;
		tot%=P;
	}

	ll good=0;
	for(int len=1;len<N-3;len++) {
		if(len*h > w) break;
		ll WF = 1LL*assign(w-len*h,len)*assign(f,len);
		ll FW = WF;
		ll WFW = 1LL*assign(w-len*h-h,len+1)*assign(f,len);
		ll FWF = 1LL*assign(w-len*h,len)*assign(f,len+1);
		good += WF+FW+WFW+FWF;
		good%=P;
	}

	// cerr<<good<<", "<<tot<<endl;

	ll num=good%P;
	ll den=tot%P;
	cout<<int(1LL*num*inv((int)den)%P)<<endl;
}