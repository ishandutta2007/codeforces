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

int n, m, res;
int T[100005], S[100005], in[100005];
bool vis[100005], B[100005];
vector<int> V[100005], V2[100005];
queue<int> Q;


int DFS(int v, int ind)
{
	vis[v]=1;
	T[v]=ind;
	int s=1;
	for(int i=0; i<(int)V2[v].size(); i++)
		if(!vis[V2[v][i]]) s+=DFS(V2[v][i], ind);
	return s;
}


int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		in[b]++;
		V2[a].PB(b);
		V2[b].PB(a);
		V[a].PB(b);
	}
	//////////////////////////////////
	for(int i=1; i<=n; i++)
		if(!vis[i])
			S[i]=DFS(i, i);
	for(int i=1; i<=n; i++)
		if(in[i]==0)
			Q.push(i);
	////////////////////////////////////
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=0; i<(int)V[v].size(); i++)
		{
			in[V[v][i]]--;
			if(in[V[v][i]]==0) Q.push(V[v][i]);
		}
	}
	for(int i=1; i<=n; i++)
		if(in[i]>0)
			B[T[i]]=1;
	for(int i=1; i<=n; i++)
	{
		if(S[i]>0)
		{
			res+=S[i];
			if(!B[i]) res--;
		}
	}
	printf("%d\n", res);
	return 0;
}