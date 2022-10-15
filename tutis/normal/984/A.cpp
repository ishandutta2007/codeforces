/*input
2
1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	sort(a, a + n);
	cout << a[(n - 1) / 2] << "\n";
}