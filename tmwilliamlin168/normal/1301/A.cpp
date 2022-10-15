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
	string a, b, c;
	cin >> a >> b >> c;
	bool ok=1;
	for(int i=0; i<a.size(); ++i) {
		if(!(a[i]==c[i])&&!(b[i]==c[i])) {
			cout << "NO\n";
			ok=0;
			break;
		}
	}
	if(ok)
	cout << "YES\n";
	}
}