#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	bool t=0;
	cin >> n;
	int *a = new int[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		for(int j=0; j<i; ++j)
			t^=a[j]>a[i];
	}
	cin >> m;
	for(int i=0; i<m; ++i) {
		int l, r, s;
		cin >> l >> r;
		s=r-l+1;
		//cout << t << endl;
		t^=(s*(s-1)/2)&1;
		//cout << t << endl;
		cout << (t?"odd":"even") << "\n";
	}
}