#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, k;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k >> s;
		int a=0;
		for(char c : s)
			a+=c&1;
		int ans=n;
		for(int i=0; i<k; ++i) {
			int b=a;
			for(int j=i; j<n; j+=k)
				b-=s[j]&1;
			int dp0=0, dp1=0, dp2=0;
			for(int j=i; j<n; j+=k) {
				dp0+=s[j]&1;
				dp1+=s[j]&1^1;
				dp2+=s[j]&1;
				dp1=min(dp1, dp0);
				dp2=min(dp2, dp1);
			}
			ans=min(ans, b+dp2);
		}
		cout << ans << "\n";
	}
}