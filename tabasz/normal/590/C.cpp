#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, m, dis[5][5], res=1000000000;
int T[1005][1005], dist[5][1005][1005], A[][4]={{1, 0, -1, 0}, {0, 1, 0, -1}};
vector<PII> V[5];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin>> s;
		for(int j=1; j<=m; j++)
		{
			if(s[j-1]=='#')
				T[i][j]=-1;
			if(s[j-1]=='1')
			{
				T[i][j]=1;
				V[1].PB(MP(i, j));
			}
			if(s[j-1]=='2')
			{
				T[i][j]=2;
				V[2].PB(MP(i, j));
			}
			if(s[j-1]=='3')
			{
				T[i][j]=3;
				V[3].PB(MP(i, j));
			}
		}
	}
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			dis[i][j]=100000000;
	for(int qwe=1; qwe<=3; qwe++)
	{
		queue<PII> Q;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				dist[qwe][i][j]=100000000;
		for(int i=0; i<(int)V[qwe].size(); i++)
		{
			dist[qwe][V[qwe][i].F][V[qwe][i].S]=0;
			Q.push(V[qwe][i]);
		}
		while(!Q.empty())
		{
			PII x=Q.front();
			Q.pop();
			if(T[x.F][x.S]>0)
				dis[qwe][T[x.F][x.S]]=min(dis[qwe][T[x.F][x.S]], dist[qwe][x.F][x.S]);
			for(int i=0; i<4; i++)
			{
				PII y=MP(x.F+A[0][i], x.S+A[1][i]);
				int l=dist[qwe][x.F][x.S];
				if(T[y.F][y.S]<1)
					l++;
				if(T[y.F][y.S]!=-1 && dist[qwe][y.F][y.S]>l)
				{
					dist[qwe][y.F][y.S]=l;
					Q.push(y);
				}
			}
		}
	}
	res=min(min(res, dis[1][2]+dis[1][3]), min(dis[2][1]+dis[2][3], dis[3][1]+dis[3][2]));
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(T[i][j]==0)
			{
				res=min(res, dist[1][i][j]+dist[2][i][j]+dist[3][i][j]-2);
			}
		}
	}
	if(res<100000000)
		printf("%d\n", res);
	else
		printf("-1\n");
	return 0;
}