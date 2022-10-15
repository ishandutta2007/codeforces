#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int c[k]={};
	for(int i=0, ai; i<n; ++i) {
		cin >> ai, --ai;
		++c[ai];
	}
	int ans=0, op=0;
	for(int i=0; i<k; ++i) {
		ans+=c[i]/2*2;
		op+=c[i]%2;
	}
	cout << ans+(op+n%2)/2;
}