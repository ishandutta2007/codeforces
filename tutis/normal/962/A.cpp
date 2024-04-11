/*input
4
1 3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int s = accumulate(a, a + n, 0);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum * 2 >= s)
		{
			cout << i + 1 << "\n";
			return 0;
		}
	}

}