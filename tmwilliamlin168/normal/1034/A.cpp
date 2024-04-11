#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5, mxA=1.5e7;
int n, a[mxN], g, spf[mxA+1], b[mxA+1], ans;
bool c[mxA+1];
vector<int> ps;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=2; i<=mxA; ++i) {
		if(!c[i]) {
			ps.push_back(i);
			spf[i]=i;
		}
		for(int j=0; j<ps.size()&&i*ps[j]<=mxA&&ps[j]<=spf[i]; ++j) {
			c[i*ps[j]]=1;
			spf[i*ps[j]]=ps[j];
		}
	}
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		g=__gcd(a[i], g);
	}
	for(int i=0; i<n; ++i) {
		a[i]/=g;
		while(a[i]>1) {
			int cf=spf[a[i]];
			++b[cf];
			while(a[i]%cf==0)
				a[i]/=cf;
		}
	}
	for(int i=2; i<=mxA; ++i)
		ans=max(b[i], ans);
	cout << (!ans?-1:n-ans);
}