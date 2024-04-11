#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100005
using namespace std;
int T, n, cnt[4];
char t[4] = {'A', 'N', 'T', 'O'};
char s[maxn];
int f[maxn];
inline void add(int x, int data)
{
	for(; x <= n; x += (x & (-x))) f[x] += data;
}
inline long long que(int x)
{
	int res = 0;
	for(; x; x -= (x & (-x))) res += f[x];
	return res;
}
long long check(int ans)
{
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int i = 1; i <= n; i++) add(i, 1);
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		if(s[i] != t[ans / 6]) continue;
//		putchar(t[ans / 6]);
//		putchar(' ');
		res += que(i - 1);
		add(i, -1);
	}
	for (int i = ans / 6 + 1; i < 4; i++) t[i - 1] = t[i];
	ans %= 6;
//	printf("%d  ", res);
	for (int i = 1; i <= n; i++)
	{
		if(s[i] != t[ans / 2]) continue;
//		putchar(t[ans / 2]);
//		putchar(' ');
		res += que(i - 1);
		add(i, -1);
	}
	for (int i = ans / 2 + 1; i < 4; i++) t[i - 1] = t[i];
	ans %= 2;
//	printf("%d  ", res);
	for (int i = 1; i <= n; i++)
	{
		if(s[i] != t[ans]) continue;
//		putchar(t[ans]);
//		putchar(' ');
		res += que(i - 1);
		add(i, -1);
	}
	for (int i = ans + 1; i < 4; i++) t[i - 1] = t[i];
//	printf("%d  ", res);
	for (int i = 1; i <= n; i++)
	{
		if(s[i] != t[0]) continue;
//		putchar(t[0]);
//		putchar(' ');
		res += que(i - 1);
		add(i, -1);
	}
//	putchar('\n');
//	printf("%d\n", res);
	return res;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++)
		{
			if(s[i] == 'A') cnt[0]++;
			if(s[i] == 'N') cnt[1]++;
			if(s[i] == 'T') cnt[2]++;
			if(s[i] == 'O') cnt[3]++;
		}
		int ans = 0;
		for (int i = 0; i < 24; i++)
		{
			t[0] = 'A', t[1] = 'N', t[2] = 'T', t[3] = 'O';
			long long tmp1 = check(i);
//			printf("%d %d\n", i, tmp1);
			t[0] = 'A', t[1] = 'N', t[2] = 'T', t[3] = 'O';
			long long tmp2 = check(ans);
			if(tmp1 > tmp2) ans = i;
		}
			t[0] = 'A', t[1] = 'N', t[2] = 'T', t[3] = 'O';
		for (int i = 1; i <= cnt[ans / 6]; i++)
		{
			putchar(t[ans / 6]);
		}
		for (int i = ans / 6 + 1; i < 4; i++)
		{
			t[i - 1] = t[i];
			cnt[i - 1] = cnt[i];
		}
		ans %= 6;
		for (int i = 1; i <= cnt[ans / 2]; i++)
		{
			putchar(t[ans / 2]);
		}
		for (int i = ans / 2 + 1; i < 4; i++)
		{
			t[i - 1] = t[i];
			cnt[i - 1] = cnt[i];
		}
		ans %= 2;
		for (int i = 1; i <= cnt[ans]; i++)
		{
			putchar(t[ans]);
		}
		for (int i = ans + 1; i < 4; i++)
		{
			t[i - 1] = t[i];
			cnt[i - 1] = cnt[i];
		}
		for (int i = 1; i <= cnt[0]; i++)
		{
			putchar(t[0]);
		}
		putchar('\n');
	}
	return 0;
}