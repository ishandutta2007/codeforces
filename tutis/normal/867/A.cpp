/*input
10
SSFFSFFSFF
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == 'F' && s[i - 1] == 'S')
			x++;
		if (s[i] == 'S' && s[i - 1] == 'F')
			x--;
	}
	if (x > 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}