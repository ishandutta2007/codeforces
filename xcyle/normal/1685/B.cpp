/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int a, b, c, d, t[2];
char s[200005];
void solve()
{
	a = read(), b = read(), t[0] = read(), t[1] = read();
	scanf("%s", s + 1); int n = strlen(s + 1);
	int cnt[2] = {0, 0};
	ru(i, 1, n) cnt[s[i] - 'A']++;
	if(cnt[0] != a + t[0] + t[1] || cnt[1] != b + t[0] + t[1]) {printf("NO\n");
	return;
	}
	int las = 0, tot = 0;
	vector<int> buc[2]; buc[0].clear(), buc[1].clear();
	ru(i, 1, n)
	{
		int j = i;
		while(j < n && s[j + 1] != s[j]) j++;
		if(s[i] == s[j]) tot += (j - i) / 2;
		else buc[s[i] - 'A'].push_back((j - i + 1) / 2), t[s[i] - 'A'] -= (j - i + 1) / 2;
//		printf("%d %d\n", i, j);
		i = j;
	}
	ru(j, 0, 1) sort(buc[j].begin(), buc[j].end(), greater<int>());
//	printf("%d %d %d\n", t[0], t[1], tot);
	if(t[1] > 0)
	{
		swap(buc[0], buc[1]), swap(t[0], t[1]);
	}
	for (auto x: buc[1])
	{
//		printf("!!! %d\n", x);
		int tmp = min(x, -t[1]);
		if(tmp > 1)
		{
			t[0] -= tmp - 1;
			t[1] += tmp;
		}
	}
	if(t[0] + max(0, t[1]) > tot) {printf("NO\n");}
	else printf("YES\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}