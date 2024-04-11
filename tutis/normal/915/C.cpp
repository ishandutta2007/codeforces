/***
3921
10000
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool ok(deque<char> a, deque<char>b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	deque<char> a, b;
	string A, B;
	cin >> A >> B;
	for (char x : A)
		a.push_back(x);
	for (char x : B)
		b.push_back(x);
	sort(a.begin(), a.end(), [](char a, char b) {return a > b;});
	if (b.size() > a.size())
	{
		for (char x : a)
			cout << x;
		cout << endl;
		return 0;
	}
	string x = "";
	string paime = "";
	while (!a.empty())
	{
		if (a.size() == 1)
		{
			x.push_back(a[0]);
			a.clear();
			break;
		}
		sort(a.begin(), a.end(), [](char a, char b) {return a > b;});
		for (int i = 0; i < a.size(); i++)
		{
			deque<char> y;
			for (int j = 0; j < a.size(); j++)
				if (i != j)
					y.push_back(a[j]);
			sort(y.begin(), y.end());
			y.push_front(a[i]);
			if (x < paime || ok(y, b))
			{
				x.push_back(a[i]);
				deque<char>x;
				for (int j = 0; j < a.size(); j++)
					if (i != j)
						x.push_back(a[j]);
				a = x;
				paime.push_back(b[0]);
				b.pop_front();
				break;
			}
		}
	}
	cout << x << endl;
}