#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

char C[2][30];
int n, m;
vector<pair<int, int> > V[30][30];
bool vis[30][30];

int DFS(int x, int y)
{
	int res=1;
	vis[x][y]=1;
	for(int i=0; i<(int)V[x][y].size(); i++)
	{
		if(!vis[V[x][y][i].F][V[x][y][i].S]) res+=DFS(V[x][y][i].F, V[x][y][i].S);
	}
	return res;
}

int main()
{
	scanf("%d%d\n", &n, &m);
	for(int i=0; i<n; i++)
	{
		char c;
		scanf("%c", &c);
		C[0][i]=c;
	}
	scanf("\n");
	for(int i=0; i<m; i++)
	{
		char c;
		scanf("%c", &c);
		C[1][i]=c;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int ii=i, jj=j;
			if(C[0][i]=='<') jj--;
			else jj++;
			if(C[1][j]=='^') ii--;
			else ii++;
			if(ii>=0 && ii<n) V[i][j].PB(MP(ii, j));
			if(jj>=0 && jj<m) V[i][j].PB(MP(i, jj));
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			for(int ii=0; ii<n; ii++)
					for(int jj=0; jj<m; jj++)
						vis[ii][jj]=0;
			if(DFS(i, j)<n*m)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}