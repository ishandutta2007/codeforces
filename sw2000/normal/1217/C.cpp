#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int inf = 0x3fff3fff;

int f(string a)
{
	int ret = 0;
	for (int i = 0; i<a.size(); i++)
	{
		ret <<= 1;
		if (a[i] == '1')ret++;
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int ans = 0, cnt = 0;
		string a;
		cin >> a;
		for (int i = 0; i<a.size(); i++)
		{
			if (a[i] == '0')cnt++;
			else
			{
				for (int j = 1; i+j<=a.size(); j++)
				{
					if (f(a.substr(i, j)) <= j+cnt)
					{
						ans++;
					}
					else break;
				}
				cnt = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}