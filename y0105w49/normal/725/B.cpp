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
	string s; cin>>s;
	char c=s.back();
	s=s.substr(0,s.size()-1);
	istringstream iss(s);
	ll n; iss>>n;
	--n;
	ll m=(n/4);
	ll ans=m*(6+6+4);
	n-=m*4;
	assert(0<=n&&n<4);
	if(n%2) ans+=7;

	int ri='f'-c;
	if(c<='c') ri=3+c-'a';
	ans+=ri;
	cout<<ans+1<<endl;
}