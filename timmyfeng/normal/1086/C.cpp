#include <bits/stdc++.h>
using namespace std;

const int K = 26;

string s, a, b, tmp, ans;
bool used[K];
int k;

void solve(int i, bool great, bool less) {
	if (i == int(s.size())) {
		ans = tmp;
		int ptr = 0;
		for (int j = 0; j < k; ++j) {
			while (ptr < k && used[ptr]) {
				++ptr;
			}
			if (ans[j] == 0) {
				ans[j] = ptr + 'a';
				++ptr;
			}
		}
	} else if (great && less) {
		solve(i + 1, great, less);
	} else if (great) {
		char res = tmp[s[i] - 'a'];
		int ptr = -1;
		if (res == 0) {
			ptr = 0;
			while (ptr < k && used[ptr]) {
				++ptr;
			}
			res = ptr + 'a';
			used[ptr] = true;
			tmp[s[i] - 'a'] = res;
		}

		if (res < b[i]) {
			solve(i + 1, true, true);
		} else if (res == b[i]) {
			solve(i + 1, true, false);
		}

		if (ptr != -1) {
			used[ptr] = false;
			tmp[s[i] - 'a'] = 0;
		}
	} else if (less) {
		char res = tmp[s[i] - 'a'];
		int ptr = k;
		if (res == 0) {
			ptr = k - 1;
			while (ptr >= 0 && used[ptr]) {
				--ptr;
			}
			res = ptr + 'a';
			used[ptr] = true;
			tmp[s[i] - 'a'] = res;
		}

		if (res > a[i]) {
			solve(i + 1, true, true);
		} else if (res == a[i]) {
			solve(i + 1, false, true);
		}

		if (ptr != k) {
			used[ptr] = false;
			tmp[s[i] - 'a'] = 0;
		}
	} else {
		auto process = [&](char c) {
			if (c >= a[i] && c <= b[i]) {
				solve(i + 1, c > a[i], c < b[i]);
			}
		};

		if (tmp[s[i] - 'a'] == 0) {
			for (int j = 0; j < k; ++j) {
				if (!used[j]) {
					used[j] = true;
					tmp[s[i] - 'a'] = j + 'a';
					process(j + 'a');
					tmp[s[i] - 'a'] = 0;
					used[j] = false;
				}
			}
		} else {
			process(tmp[s[i] - 'a']);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> k >> s >> a >> b;

		ans = "";
		tmp = string(k, 0);
		solve(0, false, false);

		if (ans.empty()) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << ans << "\n";
		}
	}
}