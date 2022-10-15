/***
5 2 1 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, pos, l, r;
	cin >> n >> pos >> l >> r;
	int ans = min(abs(pos - l), abs(pos - r)) + abs(l - r) + 2;
	if (l == 1)
		ans = abs(pos - r) + 1;
	if (r == n)
		ans = abs(pos - l) + 1;
	if (l == 1 && r == n)
		ans = 0;
	cout << ans;
}