/**
6 5
1 4 3 2 5 6
2 4 3
1 6 2
4 5 4
1 3 3
2 6 3
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int P[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> P[i];
	for (int i = 0; i < m; i++)
	{
		int l, r, x;
		cin >> l >> r >> x;
		int k = 0;
		for (int i = l; i <= r; i++)
			if (P[i] > P[x] && i < x)
				k++;
			else if (P[i] < P[x] && i > x)
				k--;
		cout << (k == 0 ? "Yes\n" : "No\n");
	}
	return 0;
}