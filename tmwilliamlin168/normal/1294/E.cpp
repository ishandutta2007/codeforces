#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, ans, a1[200000];
vector<vector<int>> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	a=vector<vector<int>>(n, vector<int>(m));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> a[i][j];
	for(int i=0; i<m; ++i) {
		iota(a1, a1+n, 0);
		for(int j=0; j<n; ++j) {
			a[j][i]-=i+1;
			if(a[j][i]%m==0&&a[j][i]/m<n) {
				//cout << i << " " << j << " " << (j-a[j][i]/m+n)%n << endl;
				--a1[(j-a[j][i]/m+n)%n];
			}
		}
		int mn=1e9;
		for(int j=0; j<n; ++j)
			mn=min(a1[j]+n, mn);
		ans+=mn;
	}
	cout << ans;
}