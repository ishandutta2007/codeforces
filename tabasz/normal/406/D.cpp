#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
const int M=100003;

vector<int> V, G[M];
pair<LL, LL> P[M];
int pre[M], post[M], T[20][M], pr, po;
bool vis[M];

bool ancestor(int v, int u)
{
    if(pre[u]>pre[v] && post[u]<post[v]) return true;
    return false;
}

void DFS2(int v, int p)
{
    T[0][v]=p;
    vis[v]=1;
    pre[v]=pr;
    pr++;
    for(int i=0; i<G[v].size(); i++) if(!vis[G[v][i]]) DFS2(G[v][i], v);
    post[v]=po;
    po++;
}

int lca(int a, int b)
{
    if(ancestor(a, b)) return a;
    if(ancestor(b, a)) return b;
    int v=a, i=19;
    while(i>=0)
    {
        if(ancestor(T[i][v], b)) i--;
        else v=T[i][v];
    }
    return T[0][v];
}

LL il(int a, int b, int c)
{
	return (P[b].F-P[a].F)*(P[c].S-P[a].S)-(P[b].S-P[a].S)*(P[c].F-P[a].F);
}


int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>> n;
	for(int i=0; i<n; i++)
	{
		LL a, b;
		cin>> a >> b;
		P[i]=MP(a, b);
	}
	V.PB(n-1);
	for(int i=n-2; i>=0; i--)
	{
		
		while(V.size()>1 && il(i, V[V.size()-1], V[V.size()-2])>0) V.pop_back();
		G[i].PB(V[V.size()-1]);
		G[V[V.size()-1]].PB(i);
		V.PB(i);
	}
	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<G[i].size(); j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}*/
	DFS2(n-1, n-1);
	for(int i=1; i<20; i++)
        for(int j=0; j<n; j++)
            T[i][j]=T[i-1][T[i-1][j]];
    cin>> m;
    for(int i=0; i<m; i++)
    {
    	int a, b;
    	cin>> a >> b;
    	if(a==b) cout<< a << " ";
    	else cout<< lca(a-1, b-1)+1 << " ";
    }
	return 0;
}