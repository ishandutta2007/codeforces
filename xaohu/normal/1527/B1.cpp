#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int t, n;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> s;
		int cnt[2]{};
		for (auto c : s) 
			cnt[c - '0']++;
		if (cnt[0] % 2 == 0 || cnt[0] == 1) 
			cout << "BOB\n";
		else
			cout << "ALICE\n";
	}
	return 0;
}