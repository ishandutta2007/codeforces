#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
bool mp[110][110];
char s[110];
char ins[110];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int d[4] = {0,1,2,3};

int main()
{
	scanf("%d%d",&N,&M);
	int X1,X2,Y1,Y2;
	for (int i=1;i<=N;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=M;j++)
		{
			if (s[j] == '#') continue;
			mp[i][j] = true;
			if (s[j] == 'S')
			{
				X1 = i;
				Y1 = j;	
			}	
			if (s[j] == 'E')
			{
				X2 = i;
				Y2 = j;	
			}	
		}	
	}	
	scanf("%s",ins);
	int len = strlen(ins);
	for (int i=0;i<len;i++)ins[i] -= '0';
	int ans = 0;
	for (int i=1;i<=24;i++)
	{
		bool reach = false;
		int X = X1, Y = Y1;
		for (int j=0;j<len;j++)
		{
			X += dx[d[ins[j]]];
			Y += dy[d[ins[j]]];
			if (!mp[X][Y]) 
			{
				break;
			}
			reach |= (X == X2 && Y == Y2);
		}
		ans += reach;
		next_permutation(d,d+4);
	}
	printf("%d\n",ans);
}
/*
3 3
...
SE.
...
1
*/