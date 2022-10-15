#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int occ[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		memset(occ, -1, 4*n+4);
		bool ok=0;
		for(int i=0, a; i<n; ++i) {
			cin >> a;
			if(occ[a]<0)
				occ[a]=i;
			else {
				if(occ[a]<i-1)
					ok=1;
			}
		}
		cout << (ok?"YES":"NO") << "\n";
	}
}