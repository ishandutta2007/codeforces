#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<iostream>
#include<map>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

int T[300005], odl[300005], tmp[300005];
vector<int> V[300005];
bool vis[300005];

void DFS(int ind, int v, int od)
{
	if(odl[ind]<od)
	{
		odl[ind]=od;
		tmp[ind]=v;
	}
	vis[v]=1;
	for(int i=0; i<(int)V[v].size(); i++) if(!vis[V[v][i]]) DFS(ind, V[v][i], od+1);
}

int find(int a)
{
	if(T[a]==a) return a;
	else return T[a]=find(T[a]);
}

void onion(int a, int b)
{
	b=find(b);
	a=find(a);
	T[b]=a;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0 ;i<n; i++) T[i]=i;
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		V[a].PB(b);
		V[b].PB(a);
		if(find(a)!=find(b)) onion(a, b);
	}
	for(int i=0; i<n; i++) if(!vis[find(i)]) DFS(find(i), find(i), 0);
	for(int i=0; i<n; i++) vis[i]=0;
	for(int i=0; i<n; i++) if(!vis[find(i)]) DFS(find(i), tmp[find(i)], 0);
	for(int i=0; i<k; i++)
	{
		int a, b, c;
		scanf("%d%d", &a, &b);
		b--;
		if(a==1) printf("%d\n", odl[find(b)]);
		else
		{
			scanf("%d", &c);
			c--;
			if(find(b)!=find(c))
			{
				int bb=find(b), cc=find(c);
				odl[bb]=max(odl[bb], max(odl[cc], (odl[cc]+1)/2+(odl[bb]+1)/2+1));
				onion(bb, cc);
			}
		}
	}
	return 0;
}