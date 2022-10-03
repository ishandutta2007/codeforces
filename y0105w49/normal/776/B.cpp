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
	const int N=100<<10;
	static bool isp[N];
	for(int p=2;p<N;p++) isp[p]=1;
	for(int p=2;p<N;p++) {
		if(!isp[p]) continue;
		for(int x=p+p;x<N;x+=p) isp[x]=0;
	}

	int n; cin>>n;
	if(n==1) {
		cout<<"1\n1\n";
		return 0;
	}
	if(n==2) {
		cout<<"1\n1 1\n";
		return 0;
	}
	cout<<2<<endl;
	for(int x=2;x<=n+1;x++) {
		printf("%d%c",isp[x]+1," \n"[x==n+1]);
	}
}