#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define SZ(x) ((int)x.size())

using vi = vector<int>;

void solve() {
	string a, b;
	cin >> b >> a;
	vi delet(200);
	int j = SZ(b) - 1;
	for(int i = SZ(a) - 1; i >= 0; i--) {
		while(j >= 0 && a[i] != b[j]) delet[b[j--]] = 1;
		if(j < 0 || delet[a[i]]) {
			cout << "NO\n";
			return;
		}
		j--;
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}