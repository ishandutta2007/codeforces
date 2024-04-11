#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, a[mxN], b[6]={4, 8, 15, 16, 23, 42}, c[6];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		int j=find(b, b+6, a[i])-b;
		if(j>=6)
			continue;
		if(j&&!c[j-1])
			continue;
		++c[j];
		if(j)
			--c[j-1];
	}
	cout << n-c[5]*6;
}