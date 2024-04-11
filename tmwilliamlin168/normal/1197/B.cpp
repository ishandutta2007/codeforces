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
	ar<int, 2> mx={-1};
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		mx=max(ar<int, 2>{a[i], i}, mx);
	}
	bool ok=1;
	for(int i=mx[1]-1; ~i; --i)
		ok&=a[i+1]>a[i];
	for(int i=mx[1]+1; i<n; ++i)
		ok&=a[i-1]>a[i];
	cout << (ok?"yes":"no");
}