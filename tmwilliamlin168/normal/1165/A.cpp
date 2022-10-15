#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y, ans=0;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	for(int i=n-x; i<n; ++i)
		ans += s[i]-'0' != (i==n-y-1);
	cout << ans;
}