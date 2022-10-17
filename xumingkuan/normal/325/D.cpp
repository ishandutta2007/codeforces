#include <stdio.h>
#include <string.h>
#define MAXN 3005
int r, c, n, rc, ans = 0;
bool a[MAXN][MAXN];
int f[MAXN * MAXN * 2];
int p[8][2], num;
int getanc(int x)
{
	return f[x] == x ? x : f[x] = getanc(f[x]);
}
inline int getp(const int &x, const int &y)
{
	return (x - 1) * c + y;
}
void work(int x, int y)
{
	if(x < 1 || x > r)
		return;
	bool rev = false;
	if(y < 1)
		y = c, rev = true;
	else if(y > c)
		y = 1, rev = true;
	if(!a[x][y])
		return;
	p[num][0] = getanc(getp(x, y) + (rev ? rc : 0));
	p[num][1] = getanc(getp(x, y) + (rev ? 0 : rc));
	num++;
}
bool check(int x, int y)
{
	num = 0;
	work(x - 1, y - 1);
	work(x - 1, y);
	work(x - 1, y + 1);
	work(x, y - 1);
	work(x, y + 1);
	work(x + 1, y - 1);
	work(x + 1, y);
	work(x + 1, y + 1);
	for(int i = 0; i < num; i++)
		for(int j = 0; j < num; j++)
			if(p[i][0] == p[j][1])
				return false;
	int now0 = getanc(getp(x, y));
	int now1 = getanc(getp(x, y) + rc);
	for(int i = 0; i < num; i++)
	{
		f[p[i][0]] = now0;
		f[p[i][1]] = now1;
	}
	a[x][y] = true;
	return true;
}
int main()
{
	scanf("%d%d%d", &r, &c, &n);
	if(c == 1)
	{
		printf("0\n");
		return 0;
	}
	rc = r * c;
	memset(a, false, sizeof(a));
	for(int i = 1; i <= rc * 2; i++)
		f[i] = i;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(check(x, y))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}