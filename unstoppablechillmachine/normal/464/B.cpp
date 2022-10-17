#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

vector<vector<int>> cur;

bool check() {
	ll mn = 1e18;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			ll sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += (cur[i][k] - cur[j][k]) * 1ll * (cur[i][k] - cur[j][k]);
			}		
			mn = min(mn, sum);
		}
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			ll sum = 0;
			for (int k = 0; k < 3; k++) {
				sum += (cur[i][k] - cur[j][k]) * 1ll * (cur[i][k] - cur[j][k]);
			}
			if (sum == mn) {
				cnt1++;
			}
			if (sum == 2 * mn) {
				cnt2++;
			}
			if (sum == 3 * mn) {
				cnt3++;
			}
		}
	}
	return (cnt1 == 12 && cnt2 == 12 && cnt3 == 4);
}

vector<vector<int>> arr(8, vector<int>(3));

void rec(int num) {
	if (num == 8) {
		if (check()) {
			cout << "YES\n";
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 3; j++) {
					cout << cur[i][j] << ' ';
				}
				cout << '\n';
			}
			exit(0);
		}
		return;
	}
	sort(all(arr[num]));
	do {
		cur.pb(arr[num]);
		rec(num + 1);
		cur.pop_back();	
	} while (next_permutation(all(arr[num])));
}

signed main() {
	for (int i = 0; i < 8; i++) {
		for (int j =0 ; j < 3; j++) {
			cin >> arr[i][j];
		}
	}		
	rec(0);
	cout << "NO\n";
}