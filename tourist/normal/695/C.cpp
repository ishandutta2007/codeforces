#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pw(x) (1ll << (x))

using namespace std;
int k, n;
int x[2222], y[2222], xx[2222], yy[2222];

vector<int> ve[11][2222];

int incov[2222];

int can(int covered, vector<int> tg, int mask) {
	if (tg.size() == 0) return 1;

	for (int i = 0; i < k; i++) if ((mask & pw(i)) == 0) {
		vector<int> t = tg;
		int h = t.back();
		t.pop_back();
		incov[h]++;
		for (int j = 0; j < ve[i][h].size(); j++) {
			int need = ve[i][h][j];
			if (incov[need] == 0) {
				int have = 0;
				for (int q = 0; q < t.size(); q++) if (t[q] == need) {
					have = 1;
					break;
				}
				if (!have) t.pb(need);
			}
			if (covered + 1 + t.size() > k) break;
		}
		if (covered + 1 + t.size() <= k && can(covered + 1, t, mask + pw(i))) {
			incov[h]--;
			return 1;
		}
		incov[h]--;
	}
	return 0;
}

int main() {
	#ifdef home
		freopen("1.in", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) cin >> xx[i] >> yy[i];

	for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) {
		long long A = yy[j] - y[i];
		long long B = x[i] - xx[j];
		long long C = -x[i] * A - y[i] * B;


		int miX = min(x[i], xx[j]);
		int maX = max(x[i], xx[j]);
		int miY = min(y[i], yy[j]);
		int maY = max(y[i], yy[j]);
		for (int l = 0; l < n; l++) if (l != j && ve[i][j].size() <= 7 && (A * xx[l] + B * yy[l] + C) == 0 && xx[l] >= miX && xx[l] <= maX && yy[l] >= miY && yy[l] <= maY) ve[i][j].pb(l);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		incov[i]++;
		for (int j = 0; j < k; j++) {
			if (can(1, ve[j][i], pw(j))) {
				ans++;
				break;
			}
		}
		incov[i]--;
	}
	cout << ans << endl;
	return 0;
}