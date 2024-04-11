#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 5e5 + 7;

int a[MAX_N], b[MAX_N], need[MAX_N];
vector <int> poses[MAX_N];
set <int> last;

int main() {
//	freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	for (int i = 1; i < MAX_N; i++) need[i] = 0;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < s; i++) {
		cin >> b[i];
		need[b[i]]++;
	}
	int now_s = 0;
	for (int i = 0; i < m; i++) {
		poses[a[i]].push_back(i);
		if (need[a[i]] != 0 && poses[a[i]].size() >= need[a[i]]) {
			if (poses[a[i]].size() == need[a[i]]) {
				now_s += need[a[i]];
				last.insert(poses[a[i]][0]);
			} else {
				int t = ((int) poses[a[i]].size()) - need[a[i]];
				last.erase(poses[a[i]][t - 1]);
				last.insert(poses[a[i]][t]);
			}
		}
		if (now_s == s) {
			int d = *last.begin();
			d -= d % k;
			int len = i - d + 1;
			if (len < k) {
				int add = k - len;
				if (d > add) {
					d -= add;
					add = 0;
				} else {
					add -= d;
					d = 0;
				}
				if (add > 0) {
					i = i + add;
				}
			}
			len = i - d + 1;
			int lost = len - k;
			if (lost > (m - (n * k))) continue;
			vector <int> ans;
			cout << lost << endl;
			for (int j = d; j <= i; j++) {
				if (need[a[j]] != 0) {
					need[a[j]]--;
				} else {
					if (lost == 0) continue;
					ans.push_back(j);
					lost--;
				}
			}
			sort(ans.begin(), ans.end());
			for (int elem : ans) cout << elem + 1 << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}