#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, x, y, z;
	cin >> a >> b >> x >> y >> z;
	ll a1=2*x+y, b1=y+3*z;
	cout << max(a1-a, 0LL)+max(b1-b, 0LL);
}