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
		int a[3], n;
		cin >> a[0] >> a[1] >> a[2] >> n;
		sort(a, a+3);
		cout << (a[2]-a[0]+a[2]-a[1]<=n&&(a[0]+a[1]+a[2]+n)%3==0?"YES":"NO") << "\n";
	}
}