/*input
fc
2
1 cfab
2 f
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int kiek[6];
int kiti[1 << 6];
int koks[100000];
bool check()
{	//kiek ir kiti
	int suma = 0;
	for (int i = 0; i < 6; i++)
		if (kiek[i] < 0)
			return false;
		else
			suma += kiek[i];
	for (int sub = 0; sub < (1 << 6); sub++)
	{
		int suma = 0;
		for (int i = 0; i < 6; i++)
		{
			if (((1 << i) & (sub)) > 0)
			{
				suma += kiek[i];
			}
		}
		int sumb = 0;
		for (int msk = 0; msk < (1 << 6); msk++)
		{
			if ((msk & sub) > 0)
				sumb += kiti[msk];
		}
		if (sumb < suma)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for (char x : s)
		kiek[x - 'a']++;
	int n = s.size();
	int m;
	cin >> m;
	fill_n(koks, 100000, (1 << 6) - 1);
	while (m--)
	{
		int i;
		string s;
		cin >> i >> s;
		i--;
		int msk = 0;
		for (char a : s)
			msk |= (1 << (a - 'a'));
		koks[i] = msk;
	}
	for (int i = 0; i < n; i++)
		kiti[koks[i]]++;
	string ans;
	for (int i = 0; i < n; i++)
	{
		kiti[koks[i]]--;
		char x = 'z';
		for (char a = 'a'; a <= 'f'; a++)
		{
			kiek[a - 'a']--;
			if (((koks[i] & (1 << (a - 'a'))) > 0) && check())
			{
				x = a;
				break;
			}
			else
			{
				kiek[a - 'a']++;
			}
		}
		if (x == 'z')
		{
			cout << ans << endl;
			cout << "Impossible" << "\n";
			return 0;
		}
		ans.push_back(x);
	}
	cout << ans << "\n";
}