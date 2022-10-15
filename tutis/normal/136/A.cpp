/*input
4
2 3 4 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool lucky(ll n)
{
	while (n > 0)
	{
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;
	}
	return true;
}
int A[1000];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		A[a] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
}