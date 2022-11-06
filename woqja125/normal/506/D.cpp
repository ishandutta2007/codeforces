#include<stdio.h>
#include<vector>
#include<set>
#include<map>

struct edge
{
	int a, b;
	edge(int A, int B):a(A), b(B){}
};
std::vector<edge> map[100001];
std::set<int> groups[100001];
int gC = 0;

bool isH[100001];

int heavyGroup[100001];
int hGC = -1;

int up[100001];
int sc[100001];
int gN[100001];
int getR(int x){return (x==up[x])?(x):(up[x]=getR(up[x]));}
void uni(int a, int b){a = getR(a); b=getR(b); if(a!=b){ up[a] = b; sc[b] += sc[a];} }


struct pair
{
	int a, b;
	pair(int A, int B){if(A>B){a = B; b = A;} else {a=A; b=B;}}
	bool operator<(const pair &A) const{return a==A.a?b<A.b:a<A.a;}
};
std::map<pair, int> ans;

int Q[100001][2];

int main()
{
	int n, m, i, j, a, b, c;
	scanf("%d%d", &n, &m);
	for(i=1; i<=m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		map[c].push_back(edge(a, b));
	}
	for(i=1; i<=n; i++) { up[i] = i; sc[i] = 1; }
	for(i=1; i<=m; i++)
	{
		if(map[i].size() == 0) continue;
		for(auto &ed: map[i]) uni(ed.a, ed.b);
		for(auto &ed: map[i])
		{
			int x = ed.a;
			int r = getR(x);
			if(gN[r] == 0)
			{
				gN[r] = ++gC;
				if(1ll*sc[r]*sc[r] > m)
				{
					heavyGroup[++hGC] = gC;
					isH[gC] = true;
				}
			}
			groups[gN[r]].insert(x);
			groups[gN[r]].insert(ed.b);
		}
		for(auto &ed: map[i])
		{
			up[ed.a] = ed.a;
			up[ed.b] = ed.b;
			sc[ed.a] = sc[ed.b] = 1;
			gN[ed.a] = gN[ed.b] = 0;
		}
	}
	int q;
	scanf("%d", &q);
	for(i=1; i<=q; i++)
	{
		scanf("%d%d", &Q[i][0], &Q[i][1]);
		ans[pair(Q[i][0], Q[i][1])] = 0;
	}
	for(i=1; i<=gC; i++)
	{
		if(!isH[i])
		{
			for(auto it = groups[i].begin(); it != groups[i].end(); it++)
			{
				for(auto ij = it; ++ij != groups[i].end();) ans[pair(*it, *ij)]++;
			}
		}
	}
	for(i=1; i<=q; i++)
	{
		int c = 0;
		for(j=0; j<=hGC; j++)
		{
			if(groups[heavyGroup[j]].count(Q[i][0]) == 1 && groups[heavyGroup[j]].count(Q[i][1]) == 1) c++;
		}
		printf("%d\n", c+ans[pair(Q[i][0], Q[i][1])]);
	}
	return 0;
}