#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int d[n]={};
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		++d[u], ++d[v];
	}
	bool ok=1;
	for(int i=0; i<n&&ok; ++i)
		ok=d[i]^2;
	cout << (ok?"YES":"NO");
}