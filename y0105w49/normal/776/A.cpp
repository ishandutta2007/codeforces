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





int32_t main() {
	string A,B; cin>>A>>B;
	int n; cin>>n;
	cout<<A<<" "<<B<<endl;
	for(;n--;) {
		string s,t; cin>>s>>t;
		if(s==A) A=t;
		else if(s==B) B=t;
		else assert(0);
		cout<<A<<" "<<B<<endl;
	}
}