#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n, m, ans[mxN];
vector<ar<int, 2>> t0, t1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0, t, l, r; i<m; ++i) {
		cin >> t >> l >> r, --l, --r;
		if(t) {
			t1.push_back({l, r});
		} else {
			t0.push_back({l, r});
		}
	}
	sort(t1.begin(), t1.end());
	int ts=0;
	for(int i=0; i<t1.size(); ++i) {
		if(!i||t1[i][0]>t1[ts-1][1])
			t1[ts++]=t1[i];
		else
			t1[ts-1][1]=max(t1[i][1], t1[ts-1][1]);
	}
	t1.resize(ts);
	for(array<int, 2> a : t0) {
		for(ar<int, 2> b : t1) {
			if(b[0]<=a[0]&&a[1]<=b[1]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i=0; i<n; ++i)
		ans[i]=n-i;
	for(ar<int, 2> a : t1)
		for(int j=a[0]; j<=a[1]; ++j)
			ans[j]=n-a[0];
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
}