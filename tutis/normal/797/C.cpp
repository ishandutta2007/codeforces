#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	deque<char> s, t, u;
	char x;
	while (cin >> x)
	{
		s.push_back(x);
	}
	int N = s.size();
	char D[N];
	D[N - 1] = s[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		D[i] = min(s[i], D[i + 1]);
	}
	while (s.size() + t.size() > 0)
	{
		while (!s.empty() and (t.empty() or D[N - s.size()] < t.back()))
		{
			char a = s.front();
			s.pop_front();
			t.push_back(a);
		}
		if (!t.empty())
		{
			char a = t.back();
			t.pop_back();
			u.push_back(a);
		}
	}
	for (char a : u)
		cout << a;
	return 0;
}