#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define ull unsigned long long

const int mxN=1e5;
int n, sa[mxN], ea[mxN], sb[mxN], eb[mxN];
ar<ull, 2> h[mxN], ha[mxN], hb[mxN];
ar<ull, 2> h2[mxN+1];

ar<ull, 2> operator+(const ar<ull, 2> &a, const ar<ull, 2> &b) {
	return {a[0]^b[0], a[1]^b[1]};
}

ull seed=69;
ull rng() {
	seed^=seed>>12;
	seed^=seed<<25;
	seed^=seed>>27;
	return seed;
}

void solve(int s[mxN], int e[mxN], ar<ull, 2> hf[mxN]) {
	vector<ar<int, 3>> v;
	for(int i=0; i<n; ++i) {
		v.push_back({s[i], e[i], i});
	}
	sort(v.begin(), v.end());
	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
	ar<ull, 2> sx={};
	for(int i=0; i<n; ++i) {
		while(pq.size()&&pq.top()[0]<v[i][0]) {
			sx=sx+h[pq.top()[1]];
			pq.pop();
		}
		hf[v[i][2]]=hf[v[i][2]]+sx;
		sx=sx+h[v[i][2]];
		pq.push({v[i][1], v[i][2]});
	}
	sx={};
	for(int i=n-1; ~i; --i) {
		int p=lower_bound(v.begin(), v.end(), ar<int, 3>{v[i][1]+1})-v.begin();
		hf[v[i][2]]=hf[v[i][2]]+h2[i+1]+h2[p];
		h2[i]=h[v[i][2]]+h2[i+1];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
	}
	for(int i=0; i<n; ++i) {
		h[i][0]=rng();
		h[i][1]=rng();
	}
	solve(sa, ea, ha);
	solve(sb, eb, hb);
	for(int i=0; i<n; ++i) {
		if(ha[i][0]^hb[i][0]||ha[i][1]^hb[i][1]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}