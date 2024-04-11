#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tr1/unordered_map>
#include<queue>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#define MP make_pair
#define PB push_back
#define s second
#define f first
#define PII pair<int,int>
#define VPII vector <pair<int,int> >
#define VI vector <int>
#define abs(a) max((a),-(a))
#define LL long long
#define LD long double
#define ALL(x) x.begin(),x.end()
#define PU putchar_unlocked
#define GU getchar_unlocked
#define DBG(x) cerr<<#x<<" "<<(x)<<endl;
using namespace std;

int T[1002][1002], a[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char c;
queue<pair<int, int> > Q;

void BFS(int i, int j)
{
	Q.push(MP(i,j));
	T[i][j]=2;
	while(!Q.empty())
	{
		pair<int, int> x=Q.front();
		Q.pop();
		for(int k=0; k<4; k++)
		{
			if(T[x.f+a[k][0]][x.s+a[k][1]]==1)
			{
				Q.push(MP(x.f+a[k][0], x.s+a[k][1]));
				if(T[x.f][x.s]==2) T[x.f+a[k][0]][x.s+a[k][1]]=3;
				else T[x.f+a[k][0]][x.s+a[k][1]]=2;
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d%c", &n, &m, &c);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			scanf("%c", &c);
			if(c=='.') T[i][j]=1;
		}
		scanf("%c", &c);
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(T[i][j]==1)
			{
				BFS(i, j);
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(T[i][j]==0) printf("-");
			if(T[i][j]==2) printf("W");
			if(T[i][j]==3) printf("B");
		}
		printf("\n");
	}
	return 0;
}