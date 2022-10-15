/*input
8
L 1
R 2
R 3
? 2
L 4
? 1
L 5
? 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int q;
	cin >> q;
	int l = 1;
	int r = -1;
	int pos[200009];
	while (q--)
	{
		char x;
		cin >> x;
		int id;
		cin >> id;
		if (l > r)
		{
			pos[id] = 0;
			l = r = 0;
			continue;
		}
		if (x == 'R')
		{
			pos[id] = r + 1;
			r++;
			continue;
		}
		if (x == 'L')
		{
			pos[id] = l - 1;
			l--;
			continue;
		}
		cout << min(pos[id] - l, r - pos[id]) << "\n";
	}
}