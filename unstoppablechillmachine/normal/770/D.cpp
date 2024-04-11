#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = (sizeof(ll) == 8) ? 1e18 : 1e9;

vector <vector <char>> arr;

void draw(char c, ll d, ll pos)
{
	arr[d][pos] = '+';
	arr[arr.size() - d - 1][pos] = '+';
	for (int i = d + 1; i < arr.size() - d - 1; i++)
	{
		arr[i][pos] = '|';
	}
	if (c == '[')
	{	
		arr[d][pos + 1] = '-';
		arr[arr.size() - d - 1][pos + 1] = '-';
	}
	else
	{
		arr[d][pos - 1] = '-';
		arr[arr.size() - d - 1][pos - 1] = '-';
	}
}

int main()
{
	srand(time(0));
	ios::sync_with_stdio(0);
#ifdef _F1A4X_
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
#endif
	ll n, d = 0, mx = 0, sz, pos = 0;
	bool sw;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '[')
		{
			d++;
		}
		else
		{
			d--;
		}
		mx = max(mx, d);
	}
	sz = mx * 2 + 1;
	arr.resize(sz, vector <char>(500, ' '));
	d = 0;
	draw(s[0], d, pos);
	pos++;
	for (int i = 1; i < n; i++)
	{
		if ((s[i] == ']') && (s[i - 1] == '['))
		{
			pos += 3;
		}
		sw = 0;
		if (s[i] == '[')
		{
			d++;
		}
		else
		{
			sw = 1;
		}
		draw(s[i], d, pos++);
		if (sw)
		{
			d--;
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(pos);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	//cout << endl;
	return 0;
}