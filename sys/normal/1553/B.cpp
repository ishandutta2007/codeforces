#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				string tmp = "";
				int k = j - ((int) t.size() - (j - i + 1));
				if (k < 0) continue;
				for (int q = i; q <= j; q++)
					tmp += s[q];
				for (int q = j - 1; q >= k; q--)
					tmp += s[q];
				if (tmp == t)
				{
					puts("YES");
					goto END;
				}
			}
		}
		puts("NO");
		END:;
	}
	return 0;
}