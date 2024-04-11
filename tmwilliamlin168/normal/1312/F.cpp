#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int t, n, x, y, z, dp1[mxN], dp2[mxN], dp3[mxN], p;
ll a[mxN];

int mex(vector<int> a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end())-a.begin());
	a.push_back(mxN);
	for(int i=0; ; ++i)
		if(i^a[i])
			return i;
}

int get(int dp[mxN], ll a) {
	if(a>200)
		return dp[(a-200)%p+200];
	return dp[a];
}

void solve() {
	cin >> n >> x >> y >> z;
	/*
	n=0;
	x=t%5+1;
	y=t/5%5+1;
	z=t/25%5+1;
	//*/
	p=-1;
	for(int i=1; i<=300&&p<0; ++i) {
		dp1[i]=mex({dp1[max(i-x, 0)], dp2[max(i-y, 0)], dp3[max(i-z, 0)]});
		dp2[i]=mex({dp1[max(i-x, 0)], dp3[max(i-z, 0)]});
		dp3[i]=mex({dp1[max(i-x, 0)], dp2[max(i-y, 0)]});
		bool ok=i>200;
		for(int k=0; k<5; ++k)
			ok&=dp1[200-k]==dp1[i-k]&&dp2[200-k]==dp2[i-k]&&dp3[200-k]==dp3[i-k];
		if(ok)
			p=i;
	}
	//cout << p-200 << endl;
	p-=200;
	/*
	bool chk=1;
	for(int k=0; k<5; ++k)
		chk&=dp1[150-k]==dp1[150-p-k]&&dp2[150-k]==dp2[150-p-k]&&dp3[150-k]==dp3[150-p-k];
	assert(chk);
	//*/
	int xo=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		xo^=get(dp1, a[i]);
	}
	int ans=0;
	for(int i=0; i<n; ++i) {
		xo^=get(dp1, a[i]);
		if(!(xo^get(dp1, max(a[i]-x, 0ll))))
			++ans;
		if(!(xo^get(dp2, max(a[i]-y, 0ll))))
			++ans;
		if(!(xo^get(dp3, max(a[i]-z, 0ll))))
			++ans;
		xo^=get(dp1, a[i]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--)
		solve();
}