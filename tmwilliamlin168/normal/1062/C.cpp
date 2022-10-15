#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5, M=1e9+7;
int n, q, p1[mxN+1], p2[mxN+1], li, ri;
string s;

ll powM(ll b, int p, ll M) {
	ll r=1;
	while(p) {
		if(p&1)
			r=b*r%M;
		p/=2;
		b=b*b%M;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q >> s;
	for(int i=0; i<n; ++i) {
		p1[i+1]=p1[i]+(s[i]=='0');
		p2[i+1]=p2[i]+(s[i]=='1');
	}
	while(q--) {
		cin >> li >> ri;
		cout << powM(2, p1[ri]-p1[li-1], M)*(powM(2, p2[ri]-p2[li-1], M)-1)%M << "\n";
	}
}