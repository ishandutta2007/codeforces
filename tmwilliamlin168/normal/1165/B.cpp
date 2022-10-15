#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int ans=0;
	for(int i=0; i<n; ++i) {
		if(a[i]>=ans+1) {
			++ans;
		}
	}
	cout << ans;
}