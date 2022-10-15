/*input
10
ooopppssss
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cin >> s;
	int i = 0;
	for (int k = 2; i < s.size(); k++)
	{
		cout << s[i];
		i += k;
	}
}