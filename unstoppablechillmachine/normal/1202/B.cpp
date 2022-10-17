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
 
const int INF = 1e9 + 10;
 
signed main() {
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int vc = SZ(s) - 1;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			vector<vector<int>> a(10, vector<int>(10, INF));
			for (int v = 0; v < 10; v++) {
				a[v][(v + x) % 10] = 1;
				a[v][(v + y) % 10] = 1;
			}
			for (int k = 0; k < 10; k++) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
					}
				}
			}
 
			int sum = 0;
			for (int i = 0; i + 1 < SZ(s); i++) {
				sum += a[s[i] - '0'][s[i + 1] - '0'];
				if (sum >= INF) {
					sum = -1;
					break;
				}
			}
			cout << max(-1, sum - vc) << ' ';
		}
		cout << '\n';
	}
}