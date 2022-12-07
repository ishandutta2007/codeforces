#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 5050;

int n; 
ll x[N], y[N];	
vector<int> ans;	

bool ok(int i) {
	if (0 < i && i + 1 < ans.size()) {
		int a = ans[i - 1];
		int b = ans[i];
		int c = ans[i + 1];
		return (x[c] - x[b]) * (x[a] - x[b]) + (y[c] - y[b]) * (y[a] - y[b]) > 0;
	}
	return 1;
}
 
int main() {
	cin >> n;
	rep(i, 1, n) cin >> x[i] >> y[i];
	rep(i, 1, n) {
		ans.push_back(i);
		per(j, 0, i - 1) {
			if (!ok(j - 1) || !ok(j) || !ok(j + 1)) 
				assert(j), swap(ans[j - 1], ans[j]);
			else break;
		}
	}
	for (auto x : ans) cout << x << " ";
	return 0;
}