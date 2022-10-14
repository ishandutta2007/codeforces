#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, q, a[mxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	int sum = 0;
	for(int i=0; i<n; ++i)
		cin >> a[i], sum+=a[i];
	while(q--) {
		int t;
		cin >> t;
		if(t==1) {
			int x;
			cin >> x;
			--x;
			sum-=a[x];
			a[x]^=1;
			sum+=a[x];	
		} else {
			int k;
			cin >> k;
			if(sum>=k)
				cout << "1\n";
			else 
				cout << "0\n";	
		}
	}	
	return 0;
}