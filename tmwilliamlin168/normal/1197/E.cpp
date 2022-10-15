#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n;
ar<int, 2> a[mxN], ans{M}, dp1[mxN], dp2[mxN];

ar<int, 2> operator+(const ar<int, 2> &a, const ar<int, 2> &b) {
	ar<int, 2> r{min(a[0], b[0])};
	if(a[0]==r[0]) {
		r[1]+=a[1];
		if(r[1]>=M)
			r[1]-=M;
	}
	if(b[0]==r[0]) {
		r[1]+=b[1];
		if(r[1]>=M)
			r[1]-=M;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int mi=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1];
		mi=max(a[i][1], mi);
	}
	sort(a, a+n);
	//cout << "h1" << endl;
	for(int i=0; i<n; ++i) {
		//cout << a[i][0] << " " << a[i][1] << endl;
	}
	//cout << "h2" << endl;
	for(int i=0; i<n; ++i) {
		int p=lower_bound(a, a+n, ar<int, 2>{a[i][1]+1, 0})-a;
		//cout << "h3" << endl;
		//cout << i << " " << p << endl;
		ar<int, 2> cd=p?dp2[p-1]:ar<int, 2>{a[i][1], 1};
		if(p) {
			cd[0]+=a[i][1];
		}
		//cout << cd[0] << " " << cd[1] << endl;
		if(a[i][0]>mi) {
			ans=ans+cd;
		}
		cd[0]-=a[i][0];
		dp2[i]=cd;
		if(i)
			dp2[i]=dp2[i]+dp2[i-1];
	}
	cout << ans[1];
}