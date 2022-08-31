#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define uint long long int
#define MP make_pair
#define PB push_back
#define N 1005
using namespace std;
int rx[4] = {0, 1, 0, -1};
int ry[4] = {1, 0, -1, 0};
int n, m;
int tr[N][N];
int pl[N][N];
vector<pair<int, int> > kol;
bool valid(int y, int x)
{
	//cout<<y<<" "<<n<<" heh "<<x<<" "<<m<<endl;
	//cout<<(y >= 1)<< (y <= n) << (x >= 1) << (x <= m) << (tr[y][x] != 1)<<endl;
	return (y >= 1) && (y <= n) && (x >= 1) && (x <= m) && (tr[y][x] != 1);
}
int dis[N][N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int sx, sy;
	int kx, ky;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dis[i][j] = N * N;
			char c;
			cin>>c;
			if (c=='E')
			{
				sy = i;
				sx = j;
				dis[sy][sx] = 0;
			}
			if (c == 'T')
			{
				tr[i][j] = 1;
			}
			if (int(c) >= int('0') && c <= int('9'))
			{
				pl[i][j] = int(c) - int('0');
			}
			if (c == 'S')
			{
				kx = j;
				ky = i;
			}
		}
	}
	
	int wynik = 0;
	kol.push_back(make_pair(sy, sx));
	for (int i = 0; i < kol.size(); i++)
	{
		int akty = kol[i].first;
		int aktx = kol[i].second;
		int aktdis = dis[akty][aktx];
		//cout<<akty<<" "<<aktx<<endl;
		for (int j = 0; j < 4; j++)
		{
			int newx = aktx + rx[j];
			int newy = akty + ry[j];
			//cout<<newy<<" "<<newx<<" "<<valid(newy, newx)<<endl;
			if (valid(newy, newx) && dis[newy][newx] == N * N)
			{
				dis[newy][newx] = aktdis + 1;
				kol.push_back(make_pair(newy, newx));
			}
		}
	}
	/* for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	} */
	int Dis = dis[ky][kx];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dis[i][j] <= Dis)
			{
				wynik += int(pl[i][j]);
			}
		}
	}
	cout<<wynik<<endl;
	
	

	
	return 0;
}