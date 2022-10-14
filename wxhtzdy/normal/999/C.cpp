#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	for (int i = 0; i < n; i++) {
		cnt[(int)(s[i] - 'a')]++;
	}	
	for (int i = 1; i < 26; i++) {
		cnt[i] += cnt[i - 1];
	}
	map<int, int> was;
	vector<int> new_cnt(26, 0);
	for (int i = 0; i < n; i++) {
		int c = (int)(s[i] - 'a');
		int x = (c == 0 ? 0 : cnt[c - 1]);
		if (x + new_cnt[c] < k) {
			was[i] = 1;
		}
		new_cnt[c]++;
	}
	for (int i = 0; i < n; i++) {
		if (!was[i]) {
			cout << s[i];
		}
	}
	return 0;
}