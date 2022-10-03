#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef long long ll;
#define fi first
#define se second
#define pb push_back








int _main() {
	const int N=1<<20;
	static bool isp[N];
	for(int p=2;p<N;p++) isp[p]=1;
	for(int p=2;p<N;p++) {
		if(!isp[p]) continue;
		for(int x=p+p;x<N;x+=p) isp[x]=0;
	}

	int n; cin>>n;
	for(int m=1;m<=1000;m++) if(!isp[n*m+1]) return m;
	assert(0);
}
int main() {
	cout<<_main()<<endl;
}