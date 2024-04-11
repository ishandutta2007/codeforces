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
#define PII pair<int, int>
const int inf=1000000000;

int n;
int A[202];

vector<int> V[202], W, R[202];
int P[202][202], odl[202], T[202];
bool vis[202];
queue<int> Q;

bool prime(int x)
{
	for(int i=2; i<x; i++) if(x%i==0) return false;
	return true;
}

bool BFS(int s, int t)
{
	for(int i=0; i<=n+1; i++) odl[i]=-1;
	odl[s]=0;
	Q.push(s);
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=0; i<(int)V[v].size(); i++)
		{
			if(P[v][V[v][i]]>0 && odl[V[v][i]]==-1)
			{
				Q.push(V[v][i]);
				odl[V[v][i]]=odl[v]+1;
			}
		}
	}
	return odl[t]!=-1;
}

int DFS(int v, int t, int mini)
{
	int res=0;
	if(v==t || mini==0) return mini;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		int u=V[v][i], x=0;
		if(P[v][u]>0 && odl[v]+1==odl[u]) x=DFS(u, t, min(mini, P[v][u]));
		P[v][u]-=x;
		P[u][v]+=x;
		res+=x;
		mini-=x;
		if(mini==0) break;
	}
	return res;
}


int maxflow(int s, int t)
{
	int res=0;
	while(BFS(s, t)) res+=DFS(s, t, inf);
	return res;
}

void DFS2(int v, int ind)
{
	//printf("DFS2 %d %d\n", v, ind);
	vis[v]=1;
	R[ind].PB(v);
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(P[v][V[v][i]]==0 && !vis[V[v][i]])
		{
			int x=V[v][i];
			vis[x]=1;
			R[ind].PB(x);
			for(int j=0; j<(int)V[x].size(); j++)
				if(P[V[x][j]][x]==0 && !vis[V[x][j]])
					DFS2(V[x][j], ind);
		}
	}
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", A+i);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(prime(A[i]+A[j]))
			{
				V[i].PB(j);
				if(A[i]%2==1) P[i][j]=1;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(A[i]%2==1)
		{
			V[0].PB(i);
			P[0][i]=2;
		}
		if(A[i]%2==0)
		{
			V[i].PB(n+1);
			P[i][n+1]=2;
		}
	}
	if(maxflow(0, n+1)<n)
	{
		printf("Impossible\n");
		return 0;
	}
	//printf("%d %d\n", P[1][2], P[1][3]);
	int qwe=0;
	for(int i=1; i<=n; i++)
	{
		if(A[i]%2==1 && !vis[i])
		{
			DFS2(i, qwe);
			qwe++;
		}
	}
	printf("%d\n", qwe);
	for(int i=0; i<qwe; i++)
	{
		printf("%d ", (int)R[i].size());
		for(int j=0; j<(int)R[i].size(); j++) printf("%d ", R[i][j]);
		printf("\n");
	}
	return 0;
}