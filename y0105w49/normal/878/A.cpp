// ayy
// ' lamo
#include <bits/stdc++.h>
// #include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const ld tau=2*acosl(-1);
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;










bool flip[10],yset[10],nset[10];


int32_t main() {
	int n; scanf("%d",&n);
	for(;n--;) {
		static char buf[4];
		int x;
		scanf("%s%d",buf,&x);
		if(*buf=='|') {
			for(int i=0;i<10;i++) if(x&(1<<i)) yset[i]=1, nset[i]=0;
		} else
		if(*buf=='&') {
			for(int i=0;i<10;i++) if(!(x&(1<<i))) nset[i]=1, yset[i]=0;
		} else
		if(*buf=='^') {
			for(int i=0;i<10;i++) if(x&(1<<i)) {
				swap(yset[i],nset[i]);
				flip[i]^=1;
			}
		} else
		assert(0);
	}

	int xx=0,oo=0,aa=1023;
	for(int i=0;i<10;i++) if(flip[i]) xx|=(1<<i);
	for(int i=0;i<10;i++) if(yset[i]) oo|=(1<<i);
	for(int i=0;i<10;i++) if(nset[i]) aa&=~(1<<i);
	printf("3\n^ %d\n| %d\n& %d\n",xx,oo,aa);
}