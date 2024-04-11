#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
// typedef __int128 INT;
typedef long long INT;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<ll> pt;
const ll inf=1e18+99;
#define fi first
#define se second
#define pb push_back


const int N=45000;
bool isp[N];
vector<int> ps;
int g(int x) {
	for(int p:ps) {
		if(p*p>x) break;
		if(!(x%p)) return x/p;
	}
	return 1;
}

int main() {
	for(int i=2;i<N;i++) isp[i]=1;
	for(int p=2;p<N;p++) {
		if(!isp[p]) continue;
		ps.pb(p);
		for(int x=p+p;x<N;x+=p) isp[x]=0;
	}

	int n; cin>>n; int be=g(n);
	if(n%2==0 && n>2) be=2;
	assert(g(2)==1);
	assert(g(13)==1);
	assert(g(25)==5);
	if(n%2==1) be=min(be,3);
	if(n%2==1 && n>=3) be=min(be,1+g(n-2));

	cout<<be<<endl;
}