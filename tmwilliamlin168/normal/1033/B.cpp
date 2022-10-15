#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

int t;
ll a, b;

bool chk(ll x) {
	for(ll i=2; i*i<=x; ++i)
		if(x%i==0)
			return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << (b<a-1||chk(a+b)?"NO":"YES") << "\n";
	}
}