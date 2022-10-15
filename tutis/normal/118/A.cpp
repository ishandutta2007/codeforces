/*input
tour
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
	for (char &x : a)
		x = tolower(x);
	string y = "";
	for (char i : a)
	{
		if (i != 'a' && i != 'o' && i != 'y' && i != 'e' && i != 'i' && i != 'u')
			y.push_back(i);
	}
	for (char i : y)
		cout << "." << i;
}