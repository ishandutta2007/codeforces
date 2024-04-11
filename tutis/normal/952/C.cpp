/*input

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 1; i < n; i++)
		if (abs(A[i] - A[i - 1]) >= 2)
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}