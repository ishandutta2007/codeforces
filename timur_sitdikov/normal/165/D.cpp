#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int col[200005], dis[200005], n, ind, pos;
vector<int> trees[100005];
vector<int> g[200005];
vector<int> chains[100005];

void init()
{
	int i, sz;
	sz=(int)chains[ind].size()*4+1;
	for(i=0; i<sz; i++)
		trees[ind].push_back(0);
}

int find_sum(int l, int r, int tl, int tr, int num)
{
	if (l>r) return 0;
	if (l==tl && r==tr) return trees[ind][num];
	int tm=(tl+tr)>>1;
	return find_sum(l, min(r, tm), tl, tm, num<<1)+find_sum(max(l, tm+1), r, tm+1, tr, (num<<1)+1);
}

void update(int tl, int tr, int num)
{
	if (tl==tr) {trees[ind][num]^=1; return;}
	int tm=(tl+tr)>>1;
	if (pos<=tm) update(tl, tm, num<<1);
	else update(tm+1, tr, (num<<1)+1);
	trees[ind][num]=trees[ind][num<<1]+trees[ind][(num<<1)+1];
}

int main()
{	
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, f, a, b, m, mx, sz1, sz2, q, tmp, tmp1, tmp2;
	scanf("%d", &n);
	for(i=n+1; i<(n<<1); i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(i);
		g[b].push_back(i);
		g[i].push_back(a);
		g[i].push_back(b);
	}
	for(mx=1, i=2; i<=n; i++)
		if (g[i].size()>g[mx].size()) mx=i;
	sz1=g[mx].size();
	dis[mx]=0;
	for(i=0; i<=2*n; i++) col[i]=-1;
	col[mx]=0;
	for(i=0; i<sz1; i++)
	{
		chains[i].push_back(mx);
		for(f=1, j=g[mx][i]; ; f++ )
		{
			col[j]=i;
			chains[i].push_back(j);
			dis[j]=f;
			if (g[j].size()==1) break;
			j= (col[g[j][0]]==-1? g[j][0]: g[j][1]);			
		}
		ind=i;
		init();
	}
	scanf("%d", &m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &q);
		if (q<3) 
		{
			scanf("%d", &a);
			a+=n;
			ind=col[a];
			pos=dis[a];
			update(0, chains[ind].size()-1, 1);
		}
		else
		{
			scanf("%d %d", &a, &b);
			if (a==b) {printf("0\n"); continue;}
			if (col[a]==col[b] || a==mx || b==mx)
			{
				ind=(a==mx? col[b]: col[a]);
				if (dis[a]>dis[b]) swap(a, b);
				tmp=find_sum(dis[a], dis[b], 0, (int)chains[ind].size()-1, 1);
				if (tmp) printf("-1\n");
				else printf("%d\n", (dis[b]-dis[a])>>1);
			}
			else
			{
				ind=col[a];
				tmp1=find_sum(0, dis[a], 0, (int)chains[ind].size()-1, 1);
				if (tmp1) {printf("-1\n"); continue;}
				ind=col[b];
				tmp2=find_sum(0, dis[b], 0, (int)chains[ind].size()-1, 1);
				if (tmp2) printf("-1\n");
				else printf("%d\n", (dis[a]>>1)+(dis[b]>>1));
			}
		}
	}
}