#include <bits/stdc++.h>
using namespace std;
int n;
int f[256];
string s, t;
vector<pair<char, char> > z;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main()
{
	cin >> n >> s >> t;
	for (int i = 0; i < 256; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		if (F(s[i]) != F(t[i]))
		{
			z.push_back(make_pair(F(s[i]), F(t[i])));
			U(s[i], t[i]);
		}
	}
	cout << z.size() << endl;
	for (pair<char, char> i: z)
	{
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}