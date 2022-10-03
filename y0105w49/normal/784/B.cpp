// '
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned short sint;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ld TAU=2*acos(-1);
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;





int32_t main() {
	int n; cin>>n;
	if(!n) return cout<<1<<endl,0;
	int Z=0;
	for(;n;n/=16) {
		int c=n%16;
		if(c==0) ++Z;
		//    1
		//    2
		//    3
		if(c==4) ++Z;
		//    5
		if(c==6) ++Z;
		//    7
		if(c==8) Z+=2;
		if(c==9) ++Z;
		if(c==0xA) ++Z;
		if(c==0xB) Z+=2;
		//    C
		if(c==0xD) ++Z;
		//    E
		//    F
	}
	cout<<Z<<endl;
}