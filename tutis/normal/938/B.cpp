/***
3
2 3 9
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int A[n + 2];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	n += 2;
	A[n - 1] = 1;
	A[n - 2] = 1000000;
	sort(A, A + n);
	int ans = 1e7;
	for (int i = 1; i < n; i++)
		ans = min(ans, max(A[i - 1] - 1, 1000000 - A[i]));
	cout << ans;
}