#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int a[n], b[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(i)
			b[i]=a[i]-a[i-1];
	}
	sort(b+1, b+n);
	int ans=0;
	for(int i=0; i<k-1; ++i)
		ans+=b[n-1-i];
	cout << a[n-1]-a[0]-ans;
}