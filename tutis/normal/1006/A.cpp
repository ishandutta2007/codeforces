/*input
5
1 2 4 5 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		cout << a - (a + 1) % 2 << " ";
	}







}