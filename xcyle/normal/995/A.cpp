#include <iostream>
#include <cstdio>
#define maxn 105
using namespace std;
int n, k, x;
int a[maxn][2], s[maxn][2], vis[maxn];
int pos[5][maxn];
int bx, by;
int cnt, ans[20005][3];
int Abs(int x)
{
	return x > 0 ? x : -x;
}
void work(int id)
{
	int tx = bx, ty = by;
	pos[bx][by] = id;
	ans[++cnt][0] = id;
	ans[cnt][1] = bx, ans[cnt][2] = by;
	//printf("%d %d %d\n", ans[cnt][0], ans[cnt][1], ans[cnt][2]);
    pos[a[id][0]][a[id][1]] = 0;
	swap(a[id][0], bx), swap(a[id][1], by);
}
void movet(int x, int y)
{
	if(pos[x][y]) work(pos[x][y]);
	else
	{
		bx = x;
		by = y;
	}
}
void moveto(int x, int y, int ban)
{
    //printf("debug: %d %d %d\n", x, y, ban);
	if(bx == a[ban][0]) movet(5 - bx, by);
	while(y != by)
	{
		if(by < y) movet(bx, by + 1);
		else movet(bx, by - 1);
	}
	if(x != bx) movet(x, y);
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s[x][0] = 1, s[x][1] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if(x == 0)
		{
			bx = 2;
			by = i;
		}
		pos[2][i] = x;
		a[x][0] = 2, a[x][1] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if(x == 0)
		{
			bx = 3;
			by = i;
		}
		pos[3][i] = x;
		a[x][0] = 3, a[x][1] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s[x][0] = 4, s[x][1] = i;
	}
	for (int i = 1; i <= k; i++)
	{
		if(Abs(s[i][0] - a[i][0]) == 1 && s[i][1] == a[i][1])
		{
			bx = a[i][0], by = a[i][1];
			ans[++cnt][0] = i;
			ans[cnt][1] = s[i][0], ans[cnt][2] = s[i][1];
			vis[i] = 1;
            pos[a[i][0]][a[i][1]] = 0;
		}
	}
	for (int i = 1; i <= k; i++)
	{
		//printf("%d %d %d %d\n", a[i][0], a[i][1], s[i][0], s[i][1]);
	}
	if(!by)
	{
		printf("-1\n");
		return 0;
	}
    //printf("%d %d\n", bx, by);
	for (int i = 1; i <= k; i++)
	{
		if(vis[i]) continue;
		if(Abs(s[i][0] - a[i][0]) != 1)
		{
			moveto(5 - a[i][0], a[i][1], i);
			work(i);
		}
		while(s[i][1] != a[i][1])
		{
			if(a[i][1] < s[i][1]) 
			{
				moveto(a[i][0], a[i][1] + 1, i);
				work(i);
			}
			else 
			{
				moveto(a[i][0], a[i][1] - 1, i);
				work(i);
			}
        //if(i == 2) exit(0);
		}
        //if(i == 2) exit(0);
		bx = a[i][0], by = a[i][1];
		ans[++cnt][0] = i;
		ans[cnt][1] = s[i][0], ans[cnt][2] = s[i][1];
        pos[a[i][0]][a[i][1]] = 0;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
	{
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
	return 0;
}