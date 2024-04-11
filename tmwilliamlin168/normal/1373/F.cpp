#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n;
ll a[mxN], b[mxN], c0[mxN], c1[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i)
			cin >> a[i];
		for(int i=0; i<n; ++i)
			cin >> b[i];
		memset(c0, 0, 8*n);
		for(int i=n-1; ~i; --i)
			c1[(i+1)%n]=b[i];
		for(int k=0; k<2; ++k) {
		for(int i=n-1; ~i; --i) {
			if(c1[(i+1)%n]+c0[(i+1)%n]>a[(i+1)%n]) {
				ll d=min(c1[(i+1)%n]+c0[(i+1)%n]-a[(i+1)%n], c1[(i+1)%n]);
				c1[(i+1)%n]-=d;
				c0[i]+=d;
			}
		}
		}
		bool ok=1;
		for(int i=0; i<n; ++i)
			ok&=c0[i]+c1[i]>=a[i];//, cout << c0[i] << " " << c1[i] << endl;
		cout << (ok?"YES":"NO") << "\n";
	}
}