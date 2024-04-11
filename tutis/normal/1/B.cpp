/*input
2
R23C55
BC23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
		vector<string>x;
		string b = "";
		for (int i = 0; i < a.size(); i++)
		{
			b.push_back(a[i]);
			if (i + 1 >= a.size() || (isalpha(a[i]) > 0) != (isalpha(a[i + 1]) > 0))
			{
				x.push_back(b);
				b = "";
			}
		}
		if (x.size() == 2)
		{
			int r = stoi(x[1]);
			string a = x[0];
			int w = 1;
			int c = 0;
			for (int i = a.size() - 1; i >= 0; i--)
			{
				c += (a[i] - 'A' + 1) * w;
				w *= 26;
			}
			cout << "R" << r << "C" << c;
		}
		if (x.size() == 4)
		{
			int r = stoi(x[1]);
			int c = stoi(x[3]);
			string a;
			while (c > 0)
			{
				a.push_back('A' + (c - 1) % 26);
				c = (c - 1) / 26;
			}
			reverse(a.begin(), a.end());
			cout << a << r;
		}
		cout << '\n';
	}


}