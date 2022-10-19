#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	vector<pair<int, int>> ax, bx;
	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	    if (i > 0) {ax.emplace_back(min(a[i - 1], a[i]), max(a[i - 1], a[i]));}
	}
	for (int i = 0; i < n; i++) {
	    cin >> b[i];
	    if (i > 0) {bx.emplace_back(min(b[i - 1], b[i]), max(b[i - 1], b[i]));}
	}
	sort(ax.begin(), ax.end());
	sort(bx.begin(), bx.end()); 
	if (!(a[0] == b[0] && a[n - 1] == b[n - 1] && equal(ax.begin(), ax.end(), bx.begin()))) {
		cout << "NO\n"; return;
	}
	cout << "YES\n";
	vector<pair<int, int>> ans;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == b[i] && a[i + 1] == b[i + 1]) {continue;}
		int pos = -1;
		for (int j = i; j < n - 1; j++) {
			if (a[j + 1] == b[i] && a[j] == b[i + 1]) {pos = j; break;}
		}
		if (pos != -1) {ans.emplace_back(i + 1, pos + 2); reverse(a + i, a + pos + 2); continue;}
		for (int j = i; j < n - 1; j++) {
			if (a[j] == b[i] && a[j + 1] == b[i + 1]) {pos = j; break;}
		}
		set<pair<int, int>> seen;
		for (int j = i; j < pos; j++) {
			seen.insert(make_pair(min(a[j], a[j + 1]), max(a[j], a[j + 1])));
		}
		int val = -1;
		for (int j = i + 1; j < n - 1; j++) {
			if (seen.find(make_pair(min(b[j], b[j + 1]), max(b[j], b[j + 1]))) != seen.end()) {
				val = j; break;
			}
		}
		int posr = -1, posl = -1;
		for (int j = i; j <= pos; j++) {
			if (min(a[j], a[j + 1]) == min(b[val], b[val + 1]) && max(a[j], a[j + 1]) == max(b[val], b[val + 1])) {posr = j; break;}
		}
		for (int j = n - 2; j >= pos; j--) {
			if (min(a[j], a[j + 1]) == min(b[val - 1], b[val]) && max(a[j], a[j + 1]) == max(b[val - 1], b[val])) {posl = j; break;}
		}
		if (posr < n - 1 && a[posr + 1] == a[posl]) {posr++;}
		else if (posl < n - 1 && a[posr] == a[posl + 1]) {posl++;}
		else if (posr < n - 1 && posl < n - 1 && a[posr + 1] == a[posl + 1]) {posr++; posl++;}
		ans.emplace_back(posr + 1, posl + 1); reverse(a + posr, a + posl + 1);
		pos = -1;
		for (int j = i; j < n - 1; j++) {
			if (a[j + 1] == b[i] && a[j] == b[i + 1]) {pos = j; break;}
		}
		ans.emplace_back(i + 1, pos + 2); reverse(a + i, a + pos + 2);
	}
	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}