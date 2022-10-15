/*input
6
tom
lucius
ginny
harry
ginny
harry
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[2][500 + 1][500 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	set<string>X;
	while (n--)
	{
		string a;
		cin >> a;
		if (X.count(a))
			cout << "YES\n";
		else
			cout << "NO\n";
		X.insert(a);
	}
}