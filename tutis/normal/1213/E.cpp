/*input
2
cb
ca

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string res = "abc";
	do
	{
		string a = {res[0], res[1]};
		string b = {res[1], res[2]};
		string c = {res[2], res[0]};
		if (n == 1)
			c = "";
		if (a != s && b != s && c != s && a != t && b != t && c != t)
		{
			cout << "YES\n";
			while (n--)
				cout << res;
			cout << "\n";
			return 0;
		}
		if (a != s && b != s && a != t && b != t && s[0] != s[1] && t[0] != t[1])
		{
			cout << "YES\n";
			cout << string(n, res[0]);
			cout << string(n, res[1]);
			cout << string(n, res[2]);
			cout << "\n";
			return 0;
		}
	} while (next_permutation(res.begin(), res.end()));
	cout << "NO\n";
}