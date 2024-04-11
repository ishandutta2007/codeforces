#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

int n, x;
vector<int> a;

int solve(vector<int> v, int bit = 29) {
	if (v.size() <= 1)
		return 0;
	vector<int> l, r;
	for (auto x : v) {
		if (x >> bit & 1)
			r.push_back(x);
		else
			l.push_back(x);
	}
	return min(solve(l, bit - 1) + max(0, (int)r.size() - 1), solve(r, bit - 1) + max(0, (int)l.size() - 1));
}
 
int main() {
	cin >> n;
	while (n--) {
		cin >> x;
		a.push_back(x);
	}
	cout << solve(a) << endl;
	return 0;
}