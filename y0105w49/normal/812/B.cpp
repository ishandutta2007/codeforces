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











bool zz(const string &s) {
	for(char c:s) if(c!='0') return 0;
	return 1;
}

int32_t main() {
	int n,m; cin>>n>>m;
	static string s[22];
	int mn[22],mx[22];
	for(int i=0;i<n;i++) cin>>s[i];
	reverse(s,s+n);
	for(;n && zz(s[n-1]);) --n;
	if(!n) return cout<<0<<endl,0;

	for(int i=0;i<n;i++) {
		int I=0;
		for(;I<m+2 && s[i][I]=='0';) ++I;
		int J=0;
		for(;J<m+2 && s[i][m+1-J]=='0';) ++J;
		mn[i]=m+1-I;
		mx[i]=m+1-J;
		// cerr<<"i="<<i<<": "<<mn[i]<<","<<mx[i]<<endl;
	}

	int ansL=0,ansR=inf;
	for(int i=0;i<n;i++) {
		if(i) ++ansL, ++ansR;
		if(zz(s[i])) {
			assert(i<n-1);
			continue;
		}
		if(i==n-1) {
			return cout<<min(ansL+mx[i], ansR+mn[i])<<endl,0;
		}
		int nansL=min(ansL+mx[i]*2, ansR+m+1);
		int nansR=min(ansR+mn[i]*2, ansL+m+1);
		ansL=nansL;
		ansR=nansR;
		// cerr<<"after i="<<i<<": "<<ansL<<","<<ansR<<endl;
	}
	assert(0);
}