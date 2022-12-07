#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t;
string s;

void solve() {
	cin >> s;
	int cnt[26]{};
	for (char c : s)
		cnt[c - 'a']++;

	string t;
	auto ad = [&](int c) {
		cnt[c]--;
		t += 'a' + c;
	};

	for (int i = 0; i < 26; i++)
		if (cnt[i] == 1) {
			ad(i);
			for (int j = 0; j < 26; j++)
				while (cnt[j])
					ad(j);
			cout << t << endl;
			return;
		}
			
	int x = 0;
	while (!cnt[x]) x++;
	
	int y = x + 1;
	while (y < 26 && !cnt[y]) y++;

	if (y == 26) {
		cout << s << endl;
		return;
	}

	if (s.length() - cnt[x] >= cnt[x] - 2) {
		ad(x);
		ad(x);
		while (y < 26) {
			ad(y);
			while (y < 26 && !cnt[y])
				y++;
			if (cnt[x])
				ad(x);
		}
		cout << t << endl;
		return;
	}

	int z = y + 1;
	while (z < 26 && !cnt[z]) z++;

	if (z < 26) {
		ad(x);
		ad(y);
		while (cnt[x])
			ad(x);
		ad(z);
		for (int i = y; i < 26; i++)
			while (cnt[i])
				ad(i);
		cout << t << endl;
		return;
	}

	ad(x);
	while (cnt[y])
		ad(y);
	while (cnt[x])
		ad(x);
	cout << t << endl;
}

int main() {
	cin >> t;
	while (t--)
		solve();
	return 0;
}