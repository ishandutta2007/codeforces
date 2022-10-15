#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll U=1e18;

vector<ll> p[2], a[2];

void recur(int i, int j, ll x) {
	if(j==p[i].size()) {
		a[i].push_back(x);
		return;
	}
	recur(i, j+1, x);
	for(; x<=U/p[i][j]; )
		recur(i, j+1, x*=p[i][j]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, pi;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> pi;
		p[i&1].push_back(pi);
	}
	recur(0, 0, 1);
	recur(1, 0, 1);
	sort(a[0].begin(), a[0].end());
	sort(a[1].begin(), a[1].end());
	ll k, l=1, r=(ll)1e18, ans=r, m, numLess;
	cin >> k;
	while(l<=r) {
		m=(l+r)/2, numLess=0;
		for(int i1=0, i2=a[1].size(); i1<a[0].size(); ++i1) {
			while(i2>0&&(a[0][i1]>=2*U/a[1][i2-1]||a[0][i1]*a[1][i2-1]>m))
				--i2;
			if(!i2)
				break;
			numLess+=i2;
			//cout << m << " " << i1 << " " << a[0][i1] << " " << i2 << endl;
		}
		//cout << m << " " << numLess << endl;
		if(numLess>=k) {
			ans=m;
			r=m-1;
		} else
			l=m+1;
	}
	cout << ans;
}