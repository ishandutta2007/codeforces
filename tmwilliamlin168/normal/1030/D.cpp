#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, m, k, a, b;
	cin >> n >> m >> k;
	if(n*m*2%k) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	a=n*m*2/k;
	b=(a-1)/m+1;
	cout << b << " 0\n";
	cout << b-1 << " " << m << "\n";
	cout << "0 " << b*m-a << "\n";
}