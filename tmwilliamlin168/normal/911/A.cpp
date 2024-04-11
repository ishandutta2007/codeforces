#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, _min=INT_MAX, ans=INT_MAX, last=-696969;
	cin >> n;
	int *a = new int[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		_min=min(a[i], _min);
	}
	for(int i=0; i<n; ++i) {
		if(a[i]==_min) {
			ans=min(i-last, ans);
			last=i;
		}
	}
	cout << ans;
}