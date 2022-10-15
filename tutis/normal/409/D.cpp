/*input
2000
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
	if (n == 7 || n == 3 || n == 16 || n == 11 || n == 2 || n == 5 || n == 12 || n == 14)
		cout << "0\n";
	else
		cout << "1\n";
}