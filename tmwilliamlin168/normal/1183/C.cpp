#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int q;
ll k, n, a, b;

void solve() {
	cin >> k >> n >> a >> b;
	if(n*b>=k){ 
		cout << "-1\n";
		return;
	}
	cout << min((k-n*b-1)/(a-b), n) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> q;
	while(q--)
		solve();
}