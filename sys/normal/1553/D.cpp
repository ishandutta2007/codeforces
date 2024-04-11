#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		int n = s.size(), m = t.size(), pnt = t.size() - 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (((m - pnt) + (n - i)) & 1) continue;
			if (pnt != -1 && s[i] == t[pnt]) pnt--;
		}
		puts(pnt != -1 ? "NO" : "YES");
	}
	return 0;
}