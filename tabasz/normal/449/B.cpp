#include<algorithm>
#include<cstdio>
#include<vector>
#include<math.h>
#include<set>
#include<queue>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

struct edge
{
	int v, w;
	bool b;
};

vector<edge> V[100001];
LL odl[100001], odl2[100001];
int res, n;
vector<LL> T[100001];
priority_queue<pair<LL, int> > Q;

edge me(int v, int w, bool b)
{
	edge x;
	x.v=v;
	x.w=w;
	x.b=b;
	return x;
}

void Dijkstra()
{
	for(int i=2; i<=n; i++) odl[i]=1000000000000000000LL;
	for(int i=2; i<=n; i++) odl2[i]=1000000000000000000LL;
	Q.push(MP(0, 1));
	while(!Q.empty())
	{
		int v=Q.top().S;
		LL od=Q.top().F*-1;
		Q.pop();
		if(od==odl[v])
		{
			for(int i=0; i<V[v].size(); i++)
			{
				if(od+(LL)V[v][i].w<odl[V[v][i].v])
				{
					odl[V[v][i].v]=od+(LL)V[v][i].w;
					Q.push(MP(odl[V[v][i].v]*-1, V[v][i].v));
				}
			}
		//	printf("qwe %d %lld %lld\n", v, odl[v], odl2[v]);
		}
	}
}

int main()
{
	int m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V[a].PB(me(b, c, 0));
		V[b].PB(me(a, c, 0));
	}
	for(int i=0; i<k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[1].PB(me(a, b, 1));
		T[a].PB(b);
	}
	for(int i=2; i<=n; i++)
	{
		sort(T[i].begin(), T[i].end());
		for(int j=T[i].size()-1; j>0; j--) {T[i].pop_back(); res++;}
	}
	Dijkstra();
	/*for(int i=1; i<=n; i++)
	{
		printf("%d: %lld %lld\n", i, odl[i], odl2[i]);
	}*/
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<V[i].size(); j++)
		{
			if(!V[i][j].b)
			{
				if(odl[i]+(LL)V[i][j].w<odl2[V[i][j].v]) odl2[V[i][j].v]=odl[i]+(LL)V[i][j].w;
			}
		}
	}
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<T[i].size(); j++)
		{
			if(odl2[i]<=T[i][j]) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}