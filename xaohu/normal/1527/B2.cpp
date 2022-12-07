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
		bool pal = 1;
		int cnt[2]{};
		for (auto c : s) 
			cnt[c - '0']++;
		rep(i, 0, n / 2)
			pal &= (s[i] == s[n - 1 - i]);
		if (pal) {
			if (cnt[0] % 2 == 0 || cnt[0] == 1) {
				cout << "BOB\n";
			}
			else {
				cout << "ALICE\n";
			}
		}
		else {
			if (n % 2 == 1 && cnt[0] == 2 && s[n / 2] == '0')
				cout << "DRAW\n";
			else
				cout << "ALICE\n";
		}					
	}
	return 0;
}