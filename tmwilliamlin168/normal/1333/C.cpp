#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN];
ll b[mxN+1], ans;
map<ll, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b[i+1]=b[i]+a[i];
	}
	for(int i=0, j=0; i<=n; ++i) {
		++mp[b[i]];
		while(mp[b[i]]>1) {
			--mp[b[j++]];
		}
		ans+=i-j;
	}
	cout << ans;
}