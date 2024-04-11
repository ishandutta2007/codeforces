#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[2*mxN], c[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			a[i+n]=a[i];
		}
		bool ok=1;
		for(int i=0; i<n&&ok; ++i)
			ok=a[i]^a[i+1];
		if(ok) {
			if(n&1) {
				cout << "3\n";
				for(int i=0; i<n-1; ++i)
					cout << 1+i%2 << " ";
				cout << "3\n";
			} else {
				cout << "2\n";
				for(int i=0; i<n; ++i)
					cout << 1+i%2 << " ";
				cout << "\n";
			}
			continue;
		}
		int s=n;
		while(a[s-1]^a[s])
			--s;
		int ans=0;
		for(int i=0, j=0; i<n; i=j) {
			for(++j; j<n&&a[s+j]!=a[s+j-1]; ++j);
			ans=max(min(j-i, 2), ans);
			for(int k=i; k<j; ++k)
				c[(s+k)%n]=1+(k-i)%2;
		}
		cout << ans << "\n";
		for(int i=0; i<n; ++i)
			cout << c[i] << " ";
		cout << "\n";
	}
}