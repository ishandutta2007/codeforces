#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

pair<int, int> query(vector<int> &a) {
	cout << "? ";
	for (auto it : a) {
		cout << it << ' ';
	}
	cout << endl;
	pair<int, int> res;
	cin >> res.F >> res.S;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> kek;
	for (int i = 1; i <= k; i++) {
		kek.pb(i);
	}
	pair<int, int> ans = query(kek);
	vector<int> kek2;
	for (int i = 1; i < ans.F; i++) {
		kek2.pb(i);
	}
	for (int i = ans.F + 1; i <= k + 1; i++) {
		kek2.pb(i);
	}
	pair<int, int> ans2 = query(kek2);
	if (ans2.S > ans.S) {
		int rez = 1;
		for (int i = 1; i <= k; i++) {
			if (i == ans.F) {
				continue;
			}
			vector<int> cur;
			for (int j = 1; j < i; j++) {
				cur.pb(j);
			}
			for (int j = i + 1; j <= k + 1; j++) {
				cur.pb(j);
			}
			pair<int, int> cans = query(cur);
			if (cans.S > ans.S) {
				rez++;
			}
		}
		cout << "! " << rez << endl;
	}
	else {
		int rez = k;
		for (int i = 1; i <= k; i++) {
			if (i == ans.F) {
				continue;
			}
			vector<int> cur;
			for (int j = 1; j < i; j++) {
				cur.pb(j);
			}
			for (int j = i + 1; j <= k + 1; j++) {
				cur.pb(j);
			}
			pair<int, int> cans = query(cur);
			if (cans.S < ans.S) {
				rez--;
			}
		}
		cout << "! " << rez << endl;	
	}
}