#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
const int MAXN = 55;
int n, m, row;
class Cube
{
public:
	int x, y, tx, ty;
}a[MAXN];
int ans[20202][4], ansn = 0;
int grid[MAXN][MAXN], tgrid[MAXN][MAXN];
int cnt[MAXN];
void mov(int id, int x, int y)
{
	ansn++;
	ans[ansn][0] = a[id].x;
	ans[ansn][1] = a[id].y;
	assert(grid[a[id].x][a[id].y] != 0);
	grid[a[id].x][a[id].y] = 0;
	a[id].x += x;
	a[id].y += y;
	ans[ansn][2] = a[id].x;
	ans[ansn][3] = a[id].y;
	assert(grid[a[id].x][a[id].y] == 0);
	grid[a[id].x][a[id].y] = id;
}
bool check_ok()
{
	for(int i = 1; i <= m; i++)
		if(a[i].x != a[i].tx || a[i].y != a[i].ty)
			return false;
	return true;
}
void output()
{
	assert(check_ok());
	printf("%d\n", ansn);
	for(int i = 1; i <= ansn; i++)
		printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	exit(0);
}
void move_x_y(int id)
{
	while(a[id].x > a[id].tx)
		mov(id, -1, 0);
	while(a[id].x < a[id].tx)
		mov(id, 1, 0);
	while(a[id].y > a[id].ty)
		mov(id, 0, -1);
	while(a[id].y < a[id].ty)
		mov(id, 0, 1);
}
void move_x_y(int id, int tx, int ty)
{
	while(a[id].x > tx)
		mov(id, -1, 0);
	while(a[id].x < tx)
		mov(id, 1, 0);
	while(a[id].y > ty)
		mov(id, 0, -1);
	while(a[id].y < ty)
		mov(id, 0, 1);
}
void solve_n_2()
{
	if(m == 1)
	{
		move_x_y(1);
		output();
	}
	if(a[1].x != a[1].tx)
	{
		if(grid[3 - a[1].x][a[1].y])
			mov(2, 0, (a[2].y == 1 ? 1 : -1));
		mov(1, (a[1].x == 1 ? 1 : -1), 0);
	}
	if(a[1].y != a[1].ty)
	{
		if(grid[a[1].x][3 - a[1].y])
			mov(2, (a[2].x == 1 ? 1 : -1), 0);
		mov(1, 0, (a[1].y == 1 ? 1 : -1));
	}
	if(a[2].x != a[2].tx && !grid[3 - a[2].x][a[2].y])
		mov(2, (a[2].x == 1 ? 1 : -1), 0);
	if(a[2].y != a[2].ty && !grid[a[2].x][3 - a[2].y])
		mov(2, 0, (a[2].y == 1 ? 1 : -1));
	if(a[2].x != a[2].tx && !grid[3 - a[2].x][a[2].y])
		mov(2, (a[2].x == 1 ? 1 : -1), 0);
	if(a[2].y != a[2].ty && !grid[a[2].x][3 - a[2].y])
		mov(2, 0, (a[2].y == 1 ? 1 : -1));
	output();
}
int main()
{
	scanf("%d%d", &n, &m);
	memset(grid, 0, sizeof(grid));
	memset(tgrid, 0, sizeof(tgrid));
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		grid[a[i].x][a[i].y] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i].tx, &a[i].ty);
		tgrid[a[i].tx][a[i].ty] = i;
	}
	if(check_ok())
		output();
	if(n == 2)
		solve_n_2();
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= m; i++)
		cnt[a[i].tx]++;
	row = 1;
	for(int i = 2; i < n; i++)
		if(cnt[i] + cnt[i + 1] <= cnt[row] + cnt[row + 1])
			row = i;
	int now = 0;
	for(int j = 1; j <= n; j++)
		if(grid[row][j])
			move_x_y(grid[row][j], row, ++now);
	for(int i = row - 1; i >= 1; i--)
	{
		for(int j = n; j >= 1; j--)
			if(grid[i][j])
			{
				int tmp = grid[i][j];
				now++;
				if(j < now)
					move_x_y(tmp, i, now);
				move_x_y(tmp, row, now);
			}
	}
	for(int i = row + 1; i <= n; i++)
	{
		for(int j = n; j >= 1; j--)
			if(grid[i][j])
			{
				int tmp = grid[i][j];
				now++;
				if(j < now)
					move_x_y(tmp, i, now);
				move_x_y(tmp, row, now);
			}
	}
	for(int i = n; i >= row + 2; i--)
	{
		for(int j = 1; j <= n; j++)
			if(tgrid[i][j])
			{
				int tmp = tgrid[i][j];
				move_x_y(tmp, row + 1, j);
				move_x_y(tmp);
			}
	}
	for(int j = 1; j <= n; j++)
		if(grid[row][j])
			mov(grid[row][j], 1, 0);
	for(int i = 1; i <= row - 1; i++)
	{
		for(int j = 1; j <= n; j++)
			if(tgrid[i][j])
			{
				int tmp = tgrid[i][j];
				move_x_y(tmp, row, j);
				move_x_y(tmp);
			}
	}
	//<=3
	vector<int> vec;
	for(int j = 1; j <= n; j++)
		if(grid[row + 1][j])
			vec.push_back(grid[row + 1][j]);
	if(vec.size() == 3)
	{
		move_x_y(tgrid[2][3]);
		for(int j = 2; j <= 3; j++)
			if(grid[3][j] && !grid[3][j - 1])
				mov(grid[3][j], 0, -1);
		move_x_y(tgrid[2][2]);
		for(int j = 2; j <= 2; j++)
			if(grid[3][j] && !grid[3][j - 1])
				mov(grid[3][j], 0, -1);
		move_x_y(tgrid[2][1]);
	}
	else if(vec.size() == 1)
	{
		move_x_y(vec[0]);
	}
	else if(vec.size() == 2)
	{
		if(a[vec[0]].tx != a[vec[1]].tx)
		{
			mov((a[vec[0]].tx == row ? vec[0] : vec[1]), -1, 0);
			move_x_y(vec[0]);
			move_x_y(vec[1]);
		}
		else if(a[vec[0]].tx == row)
		{
			if(a[vec[0]].ty > a[vec[1]].ty)
				swap(vec[0], vec[1]);
			move_x_y(vec[1]);
			move_x_y(vec[0], row + 1, a[vec[0]].ty);
			move_x_y(vec[0]);
		}
		else
		{
			if(a[vec[0]].ty > a[vec[1]].ty)
				swap(vec[0], vec[1]);
			mov(vec[0], -1, 0);
			mov(vec[1], -1, 0);
			move_x_y(vec[1]);
			move_x_y(vec[0], row, a[vec[0]].ty);
			move_x_y(vec[0]);
		}
	}
	output();
	return 0;
}