#include <iostream>

using namespace std;

const int MAX_K = 30, MAX_N = 1e6 + 7;
int s[MAX_N], a[MAX_N], b[MAX_N];
int patt[MAX_K];
int mem[MAX_K];
bool used[MAX_K];

void build_mini(int n, int k) {
	int now = 1;
	for (int i = 1; i <= n; i++) {
		if (patt[s[i]] == -1) {
			while (used[now]) now++;
			patt[s[i]] = now;
			used[now] = 1;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (patt[i] == -1) {
			while (used[now]) now++;
			patt[i] = now;
			used[now] = 1;
		}
	}
}

void build_maxi(int n, int k) {
	int now = k;
	for (int i = 1; i <= n; i++) {
		if (patt[s[i]] == -1) {
			while (used[now]) now--;
			patt[s[i]] = now;
			used[now] = 1;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (patt[i] == -1) {
			while (used[now]) now--;
			patt[i] = now;
			used[now] = 1;
		}
	}
}

bool check(int n) {
	bool is_smaller = 0, is_bigger = 0;
	for (int i = 1; i <= n; i++) {
		if (!is_smaller && patt[s[i]] > b[i]) return 0;
		if (patt[s[i]] < b[i]) is_smaller = 1;
		if (!is_bigger && patt[s[i]] < a[i]) return 0;
		if (patt[s[i]] > a[i]) is_bigger = 1;
	}
	return 1;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		int k;
		string ss, aa, bb;
		cin >> k >> ss >> aa >> bb;
		int n = ss.length();
		for (int i = 0; i < n; i++) {
			s[i + 1] = ss[i] - 'a' + 1;
			a[i + 1] = aa[i] - 'a' + 1;
			b[i + 1] = bb[i] - 'a' + 1;
		}
		for (int i = 1; i <= k; i++) {
			patt[i] = -1;
			used[i] = 0;
		}
		int now = 1;
		bool ans = 1;
		while (now <= n) {
			if (a[now] == b[now]) {
				if ((patt[s[now]] != -1 || used[a[now]]) && patt[s[now]] != a[now]) {
					cout << "NO\n";
					ans = 0;
					break;
				}
				patt[s[now]] = a[now];
				used[a[now]] = 1;
				now++;
				continue;
			}
			bool flag = 0;
			for (int i = a[now] + 1; i < b[now]; i++) {
				if ((patt[s[now]] == -1 && !used[i]) || patt[s[now]] == i) {
					patt[s[now]] = i;
					used[i] = 1;
					build_mini(n, k);	
					flag = 1;
					break;
				}
			}
			if (flag) break;
			if ((patt[s[now]] == -1 && !used[a[now]]) || patt[s[now]] == a[now]) {
				for (int i = 1; i <= k; i++) {
					mem[i] = patt[i];
				}
				patt[s[now]] = a[now];
				used[a[now]] = 1;
				build_maxi(n, k);
				if (check(n)) {
					break;
				} else {
					for (int i = 1; i <= k; i++) used[i] = 0;
					for (int i = 1; i <= k; i++) {
						patt[i] = mem[i];
						if (mem[i] != -1) used[mem[i]] = 1;
					}
				}
			}
			if ((patt[s[now]] == -1 && !used[b[now]]) || patt[s[now]] == b[now]) {
				patt[s[now]] = b[now];
				used[b[now]] = 1;
				build_mini(n, k);
				if (check(n)) {
					break;
				} 
			}
			ans = 0;
			cout << "NO\n";
			break;
		}
		if (!ans) continue;
		build_mini(n, k);
		if (!check(n)) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		string res = "";
		for (int i = 1; i <= k; i++) res += 'a' + patt[i] - 1;
		cout << res << "\n";
	}
	return 0;
}