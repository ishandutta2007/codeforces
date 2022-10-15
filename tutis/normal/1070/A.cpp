/*input
61 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int d;
int ILG[500][5099];
vector<int>PO = {1};
void IESKOM(int i, int p, string &s, int m, int suma)
{
	if (p == 0)
	{
		s[i] += suma;
		return;
	}
	for (int a = 0; a < 10; a++)
	{
		if (i == 0 && a == 0)
			continue;
		int m_ = ((m - PO[p] * a) % d + d) % d;
		int suma_ = suma - a;
		if (suma_ >= 0 && ILG[m_][suma_] <= p && ILG[m_][suma_] != 0)
		{
			s[i] += a;
			return IESKOM(i + 1, p - 1, s, m_, suma_);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int s;
	cin >> d >> s;
	for (int a = 0; a < 10; a++)
	{
		ILG[a % d][a] = 1;
	}
	for (int suma = 1; suma <= s; suma++)
	{
		queue<int>Q;
		for (int a = 0; a < d; a++)
			if (ILG[a][suma] != 0)
				Q.push({a});
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			if (ILG[(10 * x) % d][suma] == 0 || ILG[(10 * x) % d][suma] > ILG[x][suma] + 1)
			{
				ILG[(10 * x) % d][suma] = ILG[x][suma] + 1;
				Q.push({(10 * x) % d});
			}
		}
		for (int x = 1; x < 10; x++)
		{
			for (int a = 0; a < d; a++)
			{
				if (ILG[a][suma] != 0)
				{
					int b = (a * 10 + x) % d;
					if (ILG[b][suma + x] == 0 || ILG[b][suma + x] > ILG[a][suma] + 1)
					{
						ILG[b][suma + x] = ILG[a][suma] + 1;
					}
				}
			}
		}
	}
	int I = ILG[0][s];
	if (I == 0)
	{
		cout << "-1\n";
		return 0;
	}
	string ans(I, '0');
	while (PO.size() <= I)
		PO.push_back((PO.back() * 10) % d);
	IESKOM(0, I - 1, ans, 0, s);
	cout << ans << "\n";
}