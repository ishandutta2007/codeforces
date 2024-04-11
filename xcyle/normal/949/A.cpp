/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
char s[1000005];
vector<int> ans[maxn];
queue<int> q[2];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int cnt[2] = {0, 0};
	for (int i = 1; i <= n; i++) cnt[s[i] - '0']++;
	if(cnt[0] <= cnt[1])
	{
		printf("-1\n");
		return 0;
	}
	int x = cnt[0] - cnt[1];
	for (int i = 1; i <= x; i++) q[0].push(i);
	for (int i = 1; i <= n; i++)
	{
		if(q[s[i] - '0'].empty())
		{
			printf("-1\n");
			return 0;
		}
		int u = q[s[i] - '0'].front();
		q[s[i] - '0'].pop();
		q[(s[i] - '0') ^ 1].push(u);
		ans[u].push_back(i);
	}
	printf("%d\n", x);
	for (int i = 1; i <= x; i++) {
		printf("%d ", ans[i].size());
		for (auto j: ans[i]) printf("%d ", j);
		printf("\n");
	}
	return 0;
}