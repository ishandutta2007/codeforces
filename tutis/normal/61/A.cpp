/*input
1010100
0100101
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		int x = a[i] - '0';
		int y = b[i] - '0';
		cout << (x ^ y);
	}
}