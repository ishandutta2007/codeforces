#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100100;
int n, k;
char s[N];
int ans = 0;

void solve()
{
	int r = 0;
	int bal = 0;
	for (int i = 0; i < n; i++)
	{
		while(r < n && (s[r] == 'a' || bal < k))
		{
			if (s[r] == 'b') bal++;
			r++;
		}
		ans = max(ans, r - i);
		if (s[i] == 'b') bal--;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf(" %s ", s);
	solve();
	for (int i = 0; i < n; i++)
		if (s[i] == 'a')
			s[i] = 'b';
		else
			s[i] = 'a';
	solve();
	printf("%d\n", ans);

	return 0;
}