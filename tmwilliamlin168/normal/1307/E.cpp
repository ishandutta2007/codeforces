#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=1e5, M=1e9+7;
int n, m, s[mxN], f[mxN], h[mxN], al[mxN], ar[mxN];
vector<int> p[mxN], tl[mxN], tr[mxN], br[mxN];
ll a1, a2, ca1, ca2, ba[3][mxN], d[mxN];
 
ll pM(ll b, int p) {
	ll r=1;
	while(p) {
		if(p&1)
			r=r*b%M;
		b=b*b%M;
		p/=2;
	}
	return r;
}
 
array<ll, 2> ca(int a) {
	if(ba[2][a]&&ba[2][a]+ba[1][a]>1)
		return {2, ba[2][a]*(ba[1][a]+ba[2][a]-1)%M};
	if(ba[2][a]+ba[1][a])
		return {1, 2*ba[2][a]+ba[1][a]};
	return {0, 1};
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> s[i], --s[i];
		p[s[i]].push_back(i);
	}
	for(int i=0; i<m; ++i) {
		cin >> f[i] >> h[i], --f[i];
		if(h[i]>p[f[i]].size())
			continue;
		al[i]=p[f[i]][h[i]-1];
		ar[i]=p[f[i]][p[f[i]].size()-h[i]];
		tl[al[i]].push_back(i);
		tr[ar[i]].push_back(i);
		d[i]=1;
		++ba[1][f[i]];
		br[f[i]].push_back(ar[i]);
	}
	ca2=1;
	for(int i=0; i<n; ++i) {
		array<ll, 2> a=ca(i);
		ca1+=a[0];
		ca2=ca2*a[1]%M;
		sort(br[i].begin(), br[i].end());
	}
	a1=ca1;
	a2=ca2;
	for(int i=0; i<n; ++i) {
		array<ll, 2> a=ca(s[i]);
		ca1-=a[0];
		ca2=ca2*pM(a[1], M-2)%M;
		for(int j : tl[i]) {
			--ba[d[j]][s[i]];
			++d[j];
			++ba[d[j]][s[i]];
		}
		for(int j : tr[i]) {
			--ba[d[j]][s[i]];
			--d[j];
			++ba[d[j]][s[i]];
		}
		if(tl[i].size()) {
			ll b1=ca1+1, b2=ca2*tl[i].size()%M;
			ll e=br[s[i]].end()-lower_bound(br[s[i]].begin(), br[s[i]].end(), i+1)-(ar[tl[i][0]]>i);
			if(e) {
				++b1;
				b2=b2*e%M;
			}
			if(b1>a1) {
				a1=b1;
				a2=b2;
			} else if(b1==a1)
				a2=(b2+a2)%M;
		}
		a=ca(s[i]);
		ca1+=a[0];
		ca2=ca2*a[1]%M;
	}
	cout << a1 << " " << a2;
}