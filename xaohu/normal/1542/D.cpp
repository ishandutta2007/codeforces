#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 555;
const int P = 998244353;

int n;
int type[N], num[N];
ll res, dp1[N][N], dp2[N][N];

void add(ll &a, ll b) {
	a = (a + b) % P;
}

int main() { 
	cin >> n;
	rep(i, 1, n + 1) {
		string s;
		cin >> s;
		if (s == "+") {
			type[i] = 1;
			cin >> num[i];
		}
	}
	 
	rep(i, 1, n + 1) {
		if (!type[i]) continue;
		memset(dp1, 0, sizeof dp1);
		memset(dp2, 0, sizeof dp2);
		dp1[0][0] = 1;
		rep(j, 0, i) 
			rep(c, 0, j + 1) {
				// nothing
				add(dp1[j + 1][c], dp1[j][c]);
				// something
				if (type[j + 1] == 0) {
					add(dp1[j + 1][max(0, c - 1)], dp1[j][c]);
				}
				else {
					if (num[j + 1] <= num[i]) {
						add(dp1[j + 1][c + 1], dp1[j][c]);
					}
					else {
						add(dp1[j + 1][c], dp1[j][c]);
					}
				}
			}

		rep(c, 0, i)
			dp2[i + 1][c] = dp1[i - 1][c];

		rep(j, i + 1, n + 1)
			rep(c, 0, n) {
				add(dp2[j + 1][c], dp2[j][c]);

				if (type[j] == 0)
					if (c > 0)
						add(dp2[j + 1][c - 1], dp2[j][c]);
				if (type[j] == 1) {
					if (num[j] < num[i])
						add(dp2[j + 1][c + 1], dp2[j][c]);
					else
						add(dp2[j + 1][c], dp2[j][c]);
				}
			}

		rep(c, 0, n)
			add(res, dp2[n + 1][c] * num[i]);
	}
	cout << res << "\n";
	return 0;
}