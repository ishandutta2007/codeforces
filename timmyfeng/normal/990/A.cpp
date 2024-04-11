#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	int a, b;
	cin >> n >> m >> a >> b;
	cout << min(n % m * b, (m - n % m) * a) << '\n';
}