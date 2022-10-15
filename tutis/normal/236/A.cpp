/*input
wjmzbmr
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a;
	cin >> a;
	set<char>X;
	for (auto i : a)
		X.insert(i);
	if (X.size() % 2 == 1)
		cout << "IGNORE HIM!\n";
	else
		cout << "CHAT WITH HER!\n";
}