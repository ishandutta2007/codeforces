#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp push_back
#define all(a) a.begin(), a.end()
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)

using namespace std;

typedef long long base;
typedef pair <int, int> point;

const string FILENAME = "input";
const int p = 1e9 + 7, MAXN = 1e5;

int n;
map <string, bool> used;
vector <pair <string, string>> arr;
map <string, vector<int>> cnt;
set <string> res, bin;
string ans[MAXN];

string f1(pair <string, string> a) {
	string ans = "";
	ans += a.x[0];
	ans += a.x[1];
	ans += a.x[2];
	return ans;
}

string f2(pair <string, string> a) {
	string ans = "";
	ans += a.x[0];
	ans += a.x[1];
	ans += a.y[0];
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n;
	arr.resize(n);
	for (int i = n; i--;) {
		cin >> arr[i].x >> arr[i].y;
		string A = f1(arr[i]), B = f2(arr[i]);
		if (used[A]) {
			if (cnt[A].size()) {
				//cout << cnt[A].size() << endl;
				ans[cnt[A][0]] = f2(arr[cnt[A][0]]);
				res.insert(ans[cnt[A][0]]);
				bin.insert(ans[cnt[A][0]]);
				cnt[A].clear();
			}
			ans[i] = B;
			res.insert(ans[i]);
			bin.insert(ans[i]);
		} else {
			used[A] = true;
			cnt[A].pb(i);
		}
	}
	for (int i = n; i--;) {
		if (ans[i].size())
			res.insert(ans[i]);
	}
	bool OK = true;
	while (OK) {
		OK = false;
		for (int i = n; i--;) {
			if (ans[i].size()) continue;
			if (res.count(f1(arr[i])) || bin.count(f1(arr[i]))) {
				OK = true;
				ans[i] = f2(arr[i]);
				bin.insert(ans[i]);
				res.insert(ans[i]);
			}
		}
	}	
	for (int i = n; i--;) {
		if (ans[i].size() == 0) {
			ans[i] = f1(arr[i]);
			res.insert(ans[i]);
		}
	}
	if (res.size() != n) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = n; i--;) {
		cout << ans[i] << '\n';
	}
}