#include <stdio.h>

int n, m;
int map[1007][1007];
int sumrow[1007][1007], sumcol[1007][1007];
int place[27][3];
int instnum, inst[100007][2];

bool yes(int sy, int sx)
{
	int i, ny = sy, nx = sx;
	for(i = 1; i <= instnum; i++)
	{
		if(inst[i][0] == 1) // N
		{
			if(ny - inst[i][1] < 1) return false;
			if(sumcol[ny-inst[i][1]-1][nx] != sumcol[ny][nx]) return false;
			ny -= inst[i][1];
		}
		if(inst[i][0] == 2) // S
		{
			if(ny + inst[i][1] > n) return false;
			if(sumcol[ny+inst[i][1]][nx] != sumcol[ny][nx]) return false;
			ny += inst[i][1];
		}
		if(inst[i][0] == 3) // W
		{
			if(nx - inst[i][1] < 1) return false;
			if(sumrow[ny][nx-inst[i][1]-1] != sumrow[ny][nx]) return false;
			nx -= inst[i][1];
		}
		if(inst[i][0] == 4) // E
		{
			if(nx + inst[i][1] > m) return false;
			if(sumrow[ny][nx+inst[i][1]] != sumrow[ny][nx]) return false;
			nx += inst[i][1];
		}
	}
	return true;
}

int main(void)
{
	int i, j, wtf = 0;
	char c;

	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++)
	{
		scanf("\n");
		for(j = 1; j <= m; j++)
		{
			scanf("%c", &c);
			if(c == '#') map[i][j] = 1;
			else if('A' <= c && c <= 'Z')
			{
				place[c-'A'][0] = 1;
				place[c-'A'][1] = i;
				place[c-'A'][2] = j;
			}

			sumrow[i][j] = sumrow[i][j-1] + map[i][j];
			sumcol[i][j] = sumcol[i-1][j] + map[i][j];
		}
	}

	scanf("%d", &instnum);
	for(i = 1; i <= instnum; i++)
	{
		scanf("\n%c %d", &c, &inst[i][1]);
		if(c == 'N') inst[i][0] = 1;
		if(c == 'S') inst[i][0] = 2;
		if(c == 'W') inst[i][0] = 3;
		if(c == 'E') inst[i][0] = 4;
	}

	for(i = 0; i < 26; i++)
	{
		if(place[i][0] == 0) continue;
		if(yes(place[i][1], place[i][2]))
		{
			printf("%c", i+'A');
			wtf = 1;
		}
	}
	if(!wtf) printf("no solution");
	printf("\n");
	return 0;
}