#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if(a>b)
			swap(a, b);
		int l2=c-r, r2=c+r;
		l2=max(a, l2);
		r2=min(b, r2);
		cout << b-a-max(r2-l2, 0) << "\n";
	}
}