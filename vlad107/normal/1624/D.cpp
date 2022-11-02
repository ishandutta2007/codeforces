#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int M = 'z'-'a'+1;
		vector<int> cnt(M);
		string s;
		cin >> s;
		for (char c : s) ++cnt[c - 'a'];
		vector<int> len(k);
		int p = 0;
		for (int i = 0; i < M; i++) {
			while (cnt[i] >= 2) {
				len[p] += 2;
				p = (p + 1) % k;
				cnt[i] -= 2;
			}
		}
		p = k - 1;
		for (int i = 0; i < M; i++) {
			if ((p >= 0) && (cnt[i] == 1)) {
				++len[p];
				--p;
				cnt[i]--;
			}
		}
		int t = 0;
		while ((p > t) && (len[p] == len[t] - 2)) {
			--len[t];
			++len[p];
			--p;
			++t;
		}
		int mn = n;
		for (int i = 0; i < k; i++) mn = min(mn, len[i]);
		if (mn == 0) mn = 1;
		cout << mn << "\n";
	}
	return 0;
}