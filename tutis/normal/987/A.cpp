/*input
4
red
purple
yellow
orange
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a[6] = {"purple", "green", "blue", "orange", "red", "yellow"};
	string b[6] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
	set<string>x = {b[0], b[1], b[2], b[3], b[4], b[5]};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string y;
		cin >> y;
		x.erase(b[find(a, a + 6, y) - a]);
	}
	cout << x.size() << "\n";
	for (string i : x)
		cout << i << "\n";
}