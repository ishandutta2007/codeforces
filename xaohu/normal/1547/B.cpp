#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

int n;
string s;

void solve() {
	cin >> s;
	n = s.size();
	
	int l = -2, r;
	rep(i, 0, n)
		if (s[i] == 'a')
			l = r = i;

	bool ans = (l != -2);

	rep(i, 1, n) {
		if (r + 1 < n && s[r + 1] - 'a' == i)
			r++;
		else if (l > 0 && s[l - 1] - 'a' == i)
			l--;
		else
			ans = 0;
	}

	cout << (ans ? "YES\n" : "NO\n");
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}