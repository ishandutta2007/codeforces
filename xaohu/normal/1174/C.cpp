#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int N = 100111;

int n, vis[N], ans[N], id;

int main() {
	cin >> n;
	rep(i, 2, n) {
		if (!vis[i]) {
			id++;
			rep(j, 1, n / i) {
				vis[i * j] = 1;
				ans[i * j] = id;
			}
		}
		cout << ans[i] << " ";
	}
	return 0;
}