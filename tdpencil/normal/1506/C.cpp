#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()

int n, m, k;

const int mxN=2e5+5;

void solve() {
	string a, b;
	cin >> a >> b;
	n=a.size(),m=b.size();
	int ans = n+m;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<m;k++){
				for(int p=0;p<=m;p++) {
					if(i+j>n) continue;
					if(k+p>m) continue;
					if(a.substr(i, j) == b.substr(k, p)) {
						ans=min(ans, n+m-(j+p));
					}
				}
			}
		}
	}
	cout << ans << "\n";
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	//int t = 1;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}