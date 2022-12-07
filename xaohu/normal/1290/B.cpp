#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 222000;

string s;
int n, q, p[26][N];

int main() { 
	cin >> s;
	n = s.size();
	rep(i, 0, n)
		rep(j, 0, 26)
			p[j][i + 1] = p[j][i] + (s[i] - 'a' == j);

	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int cnt = 0;
		rep(i, 0, 26)
			cnt += (p[i][r] - p[i][l - 1] > 0);
		if (l == r || s[l - 1] != s[r - 1] || cnt >= 3)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}