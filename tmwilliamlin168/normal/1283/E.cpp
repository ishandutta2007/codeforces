#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, x[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x[i];
	}
	sort(x, x+n);
	int mn=0;
	for(int i=0, j=0; i<n; i=j) {
		for(; j<n&&x[j]-x[i]<=2; ++j);
		++mn;
	}
	int mx=0;
	for(int i=0; i<n; ++i) {
		if(i&&x[i-1]>x[i]) {
			++x[i];
			continue;
		}
		if(!i||x[i-1]<x[i]-1) {
			--x[i];
		}
		if(i&&x[i]==x[i-1]) {
			++x[i];
		}
		if(!i||x[i-1]<x[i])
			++mx;
	}
	cout << mn << " " << mx;
}