#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <utility>
using namespace std;
int vx, vy, sx, sy, m;
int a[205][205];
char f2[205][205], f4[205][205];
queue <pair <int, int> > q;
char pos[4] = {'U', 'L', 'D', 'R'};
char rev[256];
int pxy[256][2];
inline char getpos(int x, int y)
{
	return pos[(x + 2) ^ ((y + 1) & 2)];
}
inline void change(int &x, int &y, char c)
{
	x += pxy[c][0], y += pxy[c][1];
}
inline bool in(int x, int y)
{
	return x >= 0 && x <= 200 && y >= 0 && y <= 200;
}
inline void update(const pair <int, int> &now, int num, int x, int y)
{
	if(in(now.first + x, now.second + y) && (~a[now.first + x][now.second + y] & num) && (~a[now.first + x][now.second + y] & 1))
	{
		a[now.first + x][now.second + y] |= num;
		q.push(make_pair(now.first + x, now.second + y));
		if(num == 2)
			f2[now.first + x][now.second + y] = getpos(x, y);
		else
			f4[now.first + x][now.second + y] = getpos(x, y);
	}
}
void bfs(int x, int y, int num)
{
	q.push(make_pair(x, y));
	while(!q.empty())
	{
		pair <int, int> now = q.front();
		q.pop();
		update(now, num, -1, 0);
		update(now, num, 1, 0);
		update(now, num, 0, -1);
		update(now, num, 0, 1);
	}
}
bool v1, s1;
int vx1, vy1, sx1, sy1;
char vp1, sp1;
char seq[101010];
int seqnum;
int ux, uy = -1, dx, dy = 201, lx = 201, ly, rx = -1, ry;
inline void move(char c)
{
	change(vx, vy, c);
	if(in(vx, vy) && (a[vx][vy] & 1))
	{
		change(vx, vy, rev[c]);
		return;
	}
	change(sx, sy, c);
	if(in(sx, sy) && (a[sx][sy] & 1))
		change(sx, sy, rev[c]);
	putc(c, stdout);
	if(vx == sx && vy == sy)
		exit(0);
}
int main()
{
	pxy['U'][0] = 0, pxy['U'][1] = 1;
	pxy['L'][0] = -1, pxy['L'][1] = 0;
	pxy['D'][0] = 0, pxy['D'][1] = -1;
	pxy['R'][0] = 1, pxy['R'][1] = 0;
	rev['U'] = 'D';
	rev['L'] = 'R';
	rev['D'] = 'U';
	rev['R'] = 'L';
	scanf("%d%d%d%d%d", &vx, &vy, &sx, &sy, &m);
	if(m == 0)
	{
		printf("-1\n");
		return 0;
	}
	memset(a, 0, sizeof(a));
	a[vx += 100][vy += 100] = 2;
	a[sx += 100][sy += 100] = 4;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[u += 100][v += 100] = 1;
		if(v > uy)
			ux = u, uy = v;
		if(v < dy)
			dx = u, dy = v;
		if(u < lx)
			lx = u, ly = v;
		if(u > rx)
			rx = u, ry = v;
	}
	bfs(vx, vy, 2);
	bfs(sx, sy, 4);
	v1 = s1 = false;
	for(int i = 0; i <= 200 && !v1; i++)
		if(a[0][i] & 2)
			v1 = true, vx1 = 0, vy1 = i, vp1 = 'L';
	for(int i = 0; i <= 200 && !v1; i++)
		if(a[i][0] & 2)
			v1 = true, vx1 = i, vy1 = 0, vp1 = 'D';
	for(int i = 0; i <= 200 && !v1; i++)
		if(a[200][i] & 2)
			v1 = true, vx1 = 200, vy1 = i, vp1 = 'R';
	for(int i = 0; i <= 200 && !v1; i++)
		if(a[i][200] & 2)
			v1 = true, vx1 = i, vy1 = 200, vp1 = 'U';
	for(int i = 0; i <= 200 && !s1; i++)
		if(a[0][i] & 4)
			s1 = true, sx1 = 0, sy1 = i, sp1 = 'L';
	for(int i = 0; i <= 200 && !s1; i++)
		if(a[i][0] & 4)
			s1 = true, sx1 = i, sy1 = 0, sp1 = 'D';
	for(int i = 0; i <= 200 && !s1; i++)
		if(a[200][i] & 4)
			s1 = true, sx1 = 200, sy1 = i, sp1 = 'R';
	for(int i = 0; i <= 200 && !s1; i++)
		if(a[i][200] & 4)
			s1 = true, sx1 = i, sy1 = 200, sp1 = 'U';
	if(v1 && s1)
	{
		seqnum = 0;
		while(vx1 != vx || vy1 != vy)
		{
			seq[++seqnum] = f2[vx1][vy1];
			change(vx1, vy1, rev[f2[vx1][vy1]]);
		}
		int sx2 = sx, sy2 = sy;
		for(int i = seqnum; i >= 1; i--)
			move(seq[i]);
		for(int i = 1; i <= 500; i++)
			move(vp1);
		if(in(sx, sy))
		{
			while(sx != sx2 || sy != sy2)
				move(rev[f4[sx][sy]]);
			seqnum = 0;
			while(sx1 != sx || sy1 != sy)
			{
				seq[++seqnum] = f4[sx1][sy1];
				change(sx1, sy1, rev[f4[sx1][sy1]]);
			}
			for(int i = seqnum; i >= 1; i--)
				move(seq[i]);
			move(sp1);
			if(rev[vp1] == sp1)
			{
				for(int i = 1; i <= 300; i++)
					move((vp1 == 'L' || vp1 == 'R') ? 'U' : 'L');
				for(int i = 1; i <= 500; i++)
					move(vp1);
			}
			else
			{
				for(int i = 1; i <= 233; i++)
					move(vp1);
				for(int i = 1; i <= 233; i++)
					move(sp1);
			}
		}
		else
			for(int i = 1; i <= 300; i++)
				move((vp1 == 'L' || vp1 == 'R') ? 'U' : 'L');
		if(vx > sx)
		{
			while(sx <= rx)
				move('R');
			while(sy < ry)
				move('U');
			while(sy > ry)
				move('D');
			while(vx > sx)
				move('L');
			while(vy <= uy || sy <= uy)
				move('U');
		}
		else if(vx < sx)
		{
			while(sx >= lx)
				move('L');
			while(sy < ly)
				move('U');
			while(sy > ly)
				move('D');
			while(vx < sx)
				move('R');
			while(vy <= uy || sy <= uy)
				move('U');
		}
		if(vy > sy)
		{
			while(sy <= uy)
				move('U');
			while(sx < ux)
				move('R');
			while(sx > ux)
				move('L');
			while(vy > sy)
				move('D');
		}
		else if(vy < sy)
		{
			while(sy >= dy)
				move('D');
			while(sx < dx)
				move('R');
			while(sx > dx)
				move('L');
			while(vy < sy)
				move('U');
		}
	}
	else if((v1 || s1) || (!v1 && !s1 && (~a[sx][sy] & 2)))
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		int x, y;
		while(1)
		{
			x = sx, y = sy;
			seqnum = 0;
			while(x != vx || y != vy)
			{
				seq[++seqnum] = f2[x][y];
				change(x, y, rev[f2[x][y]]);
			}
			for(int i = seqnum; i >= 1; i--)
				move(seq[i]);
			for(int i = lx; i <= rx; i++)
				for(int j = dy; j <= uy; j++)
					if(a[i][j] & 2)
						a[i][j] ^= 2;
			a[vx][vy] |= 2;
			bfs(vx, vy, 2);
		}
	}
	return 0;
}
/*
1 2 3 1 22
0 0
0 1
0 2
0 3
0 4
1 4
2 4
3 4
4 4
5 4
5 3
5 2
5 1
5 0
4 0
3 0
2 0
1 0
2 1
2 2
4 1
4 3
*/