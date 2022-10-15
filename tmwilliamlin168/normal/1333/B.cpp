#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], b[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		int p1=n-1, p2=n-1;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			if(p1>=n-1&&a[i]>0)
				p1=i;
			if(p2>=n-1&&a[i]<0)
				p2=i;
		}
		for(int i=0; i<n; ++i) {
			cin >> b[i];
		}
		bool ok=1;
		for(int i=0; i<=min(p1, p2); ++i)
			ok&=a[i]==b[i];
		for(int i=min(p1, p2)+1; i<=max(p1, p2); ++i) {
			if(p1<p2)
				ok&=a[i]<=b[i];
			else
				ok&=a[i]>=b[i];
		}
		cout << (ok?"YES":"NO") << "\n";
	}
}