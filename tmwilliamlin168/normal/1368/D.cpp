#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll a[200000], c[20], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		for(int j=0; j<20; ++j)
			if(a[i]>>j&1)
				++c[j];
	}
	for(int i=0; i<n; ++i) {
		ll b=0;
		for(int j=0; j<20; ++j)
			if(i+1<=c[j])
				b|=1<<j;
		ans+=b*b;
	}
	cout << ans;
}