#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll r=n%m;
	cout << min(r*b, (m-r)*a);
}