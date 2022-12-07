#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int t,n,a;

int main() {
	cin>>t;
	while(t--){
		cin>>n;
		bool ok=0;
		FOR(i,n) {
			cin>>a;
			ok |= ((int)sqrt(a) * sqrt(a) != a);
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}