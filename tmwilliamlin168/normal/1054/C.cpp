#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, l[mxN], r[mxN], a[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> l[i];
	for(int i=0; i<n; ++i) {
		cin >> r[i];
		a[i]=n-l[i]-r[i];
	}
	for(int i=0; i<n; ++i) {
		int rl=0, rr=0;
		for(int j=0; j<i; ++j)
			rl+=a[j]>a[i];
		for(int j=i+1; j<n; ++j)
			rr+=a[j]>a[i];
		if(rl!=l[i]||rr!=r[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
}