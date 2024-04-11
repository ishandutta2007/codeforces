/***
5
! abc
. ad
. b
! cd
? c
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	set<char>galimi;
	for (char i = 'a'; i <= 'z'; i++)
		galimi.insert(i);
	int rado = false;
	int gaus = 0;
	while (n--)
	{
		if (galimi.size() <= 1)
			rado = true;
		char x;
		cin >> x;
		if (x == '!')
		{
			string k;
			cin >> k;
			if (rado)
				gaus++;
			set<char>X;
			for (char i : k)
				X.insert(i);
			set<char>nauji;
			for (char i : galimi)
				if (X.count(i))
					nauji.insert(i);
			galimi = nauji;
		}
		if (x == '.')
		{
			string k;
			cin >> k;
			for (char i : k)
				galimi.erase(i);
		}
		if (x == '?')
		{
			char k;
			cin >> k;
			if (rado)
			{
				gaus++;
			}
			galimi.erase(k);
		}
	}
	cout << max(0, gaus - 1);
}