/*input
hlelo
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string S;
	cin >> S;
	string t = "hello";
	auto it = S.begin();
	for (char x : t)
	{
		it = find(it, S.end(), x);
		if (it == S.end())
		{
			cout << "NO\n";
			return 0;
		}
		it++;
	}
	cout << "YES\n";

}