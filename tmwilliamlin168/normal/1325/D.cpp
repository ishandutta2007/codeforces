#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll u, v;
	cin >> u >> v;
	if(!u&&!v) {
		cout << 0;
		return 0;
	}
	if(u==v) {
		cout << "1\n" << u;
		return 0;
	}
	if(u&1^v&1||u>v) {
		cout << -1;
		return 0;
	}
	ll _and=(v-u)/2;
	ll c=u+_and, d=_and;
	if((c^d)==u) {
		cout << "2\n" << c << " " << d << "\n";
		return 0;
	}

	cout << "3\n" << (v-u)/2 << " " << (v-u)/2 << " " << u;
}