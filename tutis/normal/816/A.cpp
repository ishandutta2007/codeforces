/**
00:01
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef double d;
typedef long l;
bool palind(string a)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != a[a.size() - 1 - i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string a;
	cin >> a;
	int t = 0;
	while (!palind(a))
	{
		t++;
		a[4]++;
		if (a[4] > '9')
		{
			a[4] = '0';
			a[3]++;
			if (a[3] >= '6')
			{
				a[3] = '0';
				a[1]++;
				if (a[1] > '9')
				{
					a[1] = '0';
					a[0]++;
				}
				if (a[0] == '2' && a[1] == '4')
				{
					a[0] = '0';
					a[1] = '0';
				}
			}
		}
	}
	cout << t;
}