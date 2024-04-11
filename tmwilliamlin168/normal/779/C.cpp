#include <bits/stdc++.h>
using namespace std;
 
int a[200000], b[200000], ans;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	vector<int> c;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	for(int i=0; i<n; ++i) {
		cin >> b[i];
		a[i]-=b[i];
		ans+=b[i];
	}
	sort(a, a+n);
	for(int i=0; i<k; ++i)
		ans+=a[i];
	for(int i=k; i<n&&a[i]<0; ++i)
		ans+=a[i];
	cout << ans;
}