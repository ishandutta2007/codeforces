#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxM=1e6, M=1e9+696969;
string s, t;
int n, m, a[2], ans;
ll b1, b2, pb1[mxM+1], pb2[mxM+1], h1[mxM+1], h2[mxM+1];

pair<ll, ll> qry(int l, int r) {
	return {(h1[r+1]+(M-h1[l])*pb1[r-l+1])%M, (h2[r+1]+(M-h2[l])*pb2[r-l+1])%M};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	b1=uniform_int_distribution<int>(6969, 696969)(rng);
	b2=uniform_int_distribution<int>(69, 6969)(rng);
	pb1[0]=pb2[0]=1;
	for(int i=1; i<=mxM; ++i) {
		pb1[i]=pb1[i-1]*b1%M;
		pb2[i]=pb2[i-1]*b2%M;
	}
	cin >> s >> t;
	n=s.size();
	for(int i=0; i<n; ++i)
		++a[s[i]-'0'];
	m=t.size();
	for(int i=0; i<m; ++i) {
		h1[i+1]=(h1[i]*b1+t[i]-'a'+1)%M;
		h2[i+1]=(h2[i]*b2+t[i]-'a'+1)%M;
	}
	for(int i=1; i<=m; ++i) {
		if((ll)i*a[0]>=m)
			break;
		int b=m-i*a[0], c1=i, c2=b/a[1];
		if(b%a[1])
			continue;
		pair<ll, ll> d1={-1, -1}, d2={-1, -1};
		bool ok=1;
		for(int j=0, k=0; j<n; ++j) {
			if(s[j]=='0') {
				pair<ll, ll> e=qry(k, k+c1-1);
				if(d1.first!=-1&&e!=d1) {
					ok=0;
					break;
				}
				d1=e;
				k+=c1;
			} else {
				pair<ll, ll> e=qry(k, k+c2-1);
				if(d2.first!=-1&&e!=d2) {
					ok=0;
					break;
				}
				d2=e;
				k+=c2;
			}
		}
		ok&=d1!=d2;
		ans+=ok&&d1!=d2;
	}
	cout << ans;
}