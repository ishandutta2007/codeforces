#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, b[mxN];
long double a[mxN];
ll s;
bool c[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b[i]=floor(a[i]);
		s+=b[i];
		c[i]=abs(a[i]-b[i])>1e-7;
	}
	for(int j=0, i=0; j<-s; ++j) {
		while(!c[i])
			++i;
		++b[i++];
	}
	for(int i=0; i<n; ++i)
		cout << b[i] << "\n";
}