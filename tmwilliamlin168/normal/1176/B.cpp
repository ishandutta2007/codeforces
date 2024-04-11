#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int c[3]={};
		int n;
		cin >> n;
		for(int i=0, ai; i<n; ++i) {
			cin >> ai;
			++c[ai%3];
		}
		int ans=c[0];
		while(c[1]-3>=c[2]) {
			c[1]-=3;
			++ans;
		}
		while(c[2]-3>=c[1]) {
			c[2]-=3;
			++ans;
		}
		//ans+=max({min(c[1], c[2]), c[1]>=3?min(c[1]-3, c[2])+1:0, c[2]>=3?min(c[1], c[2]-3)+1:0});
		ans+=min(c[1], c[2]);
		cout << ans << "\n";
	}
}