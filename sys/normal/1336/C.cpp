#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005, p = 998244353;
int sizS, sizT;
string s, t;
long long ans, f[Maxn][Maxn];
bool check(int pos1, int pos2)
{
	if (pos2 >= sizT) return true;
	return s[pos1] == t[pos2];
}
int main()
{
	cin >> s >> t;
	sizS = s.size(), sizT = t.size();
	for (int i = 0; i < sizS; i++)
		f[i][i] = check(0, i);
	if (sizT == 1) ans = f[0][0];
	for (int i = 1; i < sizS; i++)
	{
		for (int lt = 0, rt = i - 1; rt < sizS; lt++, rt++)
		{
			if (lt && check(i, lt - 1)) (f[lt - 1][rt] += f[lt][rt]) %= p;
			if (rt != sizS - 1 && check(i, rt + 1)) (f[lt][rt + 1] += f[lt][rt]) %= p;
		}
		if (i + 1 >= sizT) (ans += f[0][i]) %= p;
	}
	printf("%lld", ans * 2 % p);
	return 0;
}