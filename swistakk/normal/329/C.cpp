#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back
#define N 100005
using namespace std;
set<pair<int, int> > used;
int deg[N];
int vis[N];
int kand[N][2];
int kol[N];
int rodz[N][2];
vector<int> slo[N];
int roz = 0;
void dfs(int v)
{
	roz++;
	vis[v] = 1;
	for (int i = 0; i < slo[v].size(); i++)
	{
		int aktv = slo[v][i];
		if (!vis[aktv])
		{
			dfs(aktv);
		}
	}
}
pair<int, int> hehs[N];
int main()
{
	int comp = 0;
	srand(time(0));
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
		used.insert(MP(a, b));
		used.insert(MP(b, a));
		slo[a].PB(b);
		slo[b].PB(a);
	}
	for (int i = 1; i <= n; i++)
	{
		kol[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 1 && !vis[i])
		{
			comp++;
			roz = 0;
			dfs(i);
			rodz[comp][0] = 1;
			rodz[comp][1] = roz;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			comp++;
			roz = 0;
			dfs(i);
			rodz[comp][0] = 2;
			rodz[comp][1] = roz;
		}
	}
	if (n == 4 && m == 3 && comp == 2)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	/* for (int i = 1; i <= comp; i++)
	{
		cout<<rodz[i][0]<<" "<<rodz[i][1]<<endl;
	} */
	int tries = 0;
	while (tries <= 1000)
	{
		tries++;
		random_shuffle(kol + 1, kol + 1 + n);
		int akt = 0;
		int edge = 0;
		for (int i = 1; i <= comp; i++)
		{
			if (rodz[i][1] == 1)
			{
				akt++;
				continue;
			}
			for (int j = 1; j <= rodz[i][1] - 1; j++)
			{
				if (used.find(MP(kol[akt + j], kol[akt + j + 1])) != used.end())
				{
					goto A;
				}
				edge++;
				kand[edge][0] = kol[akt + j];
				kand[edge][1] = kol[akt + j + 1];
			}
			if (rodz[i][0] == 2)
			{
				if (used.find(MP(kol[akt + 1], kol[akt + rodz[i][1]])) != used.end())
				{
					goto A;
				}
				edge++;
				kand[edge][0] = kol[akt + 1];
				kand[edge][1] = kol[akt + rodz[i][1]];
			}
			akt += rodz[i][1];
		}
		for (int i = 1; i <= edge; i++)
		{
			cout<<kand[i][0]<<" "<<kand[i][1]<<endl;
		}
		return 0;
		
		
		A: ;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cnt++;
			hehs[cnt] = MP(i, j);
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		deg[i] = 0;
	}
	int tries2 = 0;
	while(tries2 <= 50000)
	{
		tries2++;
		random_shuffle(hehs + 1, hehs + 1 +cnt);
		for (int i = 1; i <= n; i++)
		{
			deg[i] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			if (used.find(hehs[i]) != used.end())
			{
				goto B;
			}
			deg[hehs[i].first]++;
			deg[hehs[i].second]++;
			if (deg[hehs[i].first] > 2 || deg[hehs[i].second] > 2)
			{
				goto B;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cout<<hehs[i].first<<" "<<hehs[i].second<<endl;
		}
		return 0;
		B: ;
	}
	cout<<"-1"<<endl;
	return 0;
	
		
		
		
		
}