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








ll m1(int f,int T,int t0,int a,int t,int p) {
	assert(T>=0);
	assert(f>=0);
	ll tt=1LL*f*t0;
	if(tt<=T) return 0;
	if(t>=t0) return linf;

	ll save_need = tt-T;
	ll premium_bytes = (save_need + (t0-t)-1) / (t0-t);
	if(premium_bytes > f) return linf;
	ll spend_need = (premium_bytes + a-1)/a;
	return spend_need*p;
}

ll _m() {
	int f,T,t0; cin>>f>>T>>t0;
	int a1,t1,p1; cin>>a1>>t1>>p1;
	int a2,t2,p2; cin>>a2>>t2>>p2;

	ll Z=m1(f,T,t0,a1,t1,p1);
	for(int k=0;k<2;k++) {
		for(int L=0;;L++) {
			if(1LL*a1*L >= f) break;
			int rec_f=f-a1*L;
			if(1LL*t1*L*a1 > T) continue;
			int rec_T=T-t1*L*a1;
			Z=min(Z, 1LL*L*p1 + m1(rec_f,rec_T,t0,a2,t2,p2));
		}
		swap(a1,a2);
		swap(t1,t2);
		swap(p1,p2);
	}
	return Z;
}

int32_t main() {
	cout<<(_m()+1)%(linf+1)-1<<endl;
}