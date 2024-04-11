/*input
6
ADAAAA
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int A = 0;
	for (char x : s)
		A += (x == 'A');
	if (A > n - A)
	{
		cout << "Anton\n";
	}
	else if (A < n - A)
	{
		cout << "Danik\n";
	}
	else
	{
		cout << "Friendship\n";
	}
}