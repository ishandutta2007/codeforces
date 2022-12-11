#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int MAX_N = 2e5 + 7, M = 998244353;
int dp1[MAX_N], dp2[MAX_N], pref[MAX_N], all[MAX_N];

int calc(vector <int> a) {
	if (a.empty()) return 1;
	int ans = 1;
	for (int i = 0; i < (int) a.size(); i++) {
		if (a[i] == -1) {
			int j = i;
			for (; j < (int) a.size(); j++) if (a[j] != -1) break;
			j--;
			int len = j - i + 1;
			if (i == 0 && j == (int) a.size() - 1) return all[len];
			if (i == 0 || j == (int) a.size() - 1) {
				ans = (ans * pref[len]) % M;
			}
			else if (a[i - 1] == a[j + 1]) ans = (ans * dp1[len]) % M;
			else ans = (ans * dp2[len]) % M;
			i = j;
		} else {
			if (i != 0 && a[i] == a[i - 1]) return 0;
		}
	}
	return ans;
}

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	//freopen("Desktop/input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	dp1[1] = k - 1;
	dp2[1] = k - 2;
	pref[1] = k - 1;
	all[1] = k;
	for (int i = 2; i <= n; i++) {
		dp1[i] = ((k - 1) * dp2[i - 1]) % M;
		dp2[i] = (dp1[i - 1] + (k - 2) * dp2[i - 1]) % M;
		pref[i] = ((k - 1) * pref[i - 1]) % M;
		all[i] = (all[i - 1] * (k - 1)) % M;
	}
	vector <int> odd, even;
	for (int i = 0; i < n; i += 2) even.push_back(a[i]);
	for (int i = 1; i < n; i += 2) odd.push_back(a[i]);
	cout << (calc(odd) * calc(even)) % M << endl;
	return 0;
}