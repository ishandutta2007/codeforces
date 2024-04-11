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

int n, m, S[100005];
vector<PII> V[100005];
double res=0, cons;
bool vis[100005];
PII A[100005];
int W[100005];

double count(int s1, int c)
{
	double ss1=s1, ss2=n-s1, cc=c;
	double r=ss1*(ss1-1.0)*ss2+ss2*(ss2-1.0)*ss1;
	return (r*cc)/cons;
}

int DFS(int v)
{
	vis[v]=1;
	int s=1;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i].F])
		{
			int ss=DFS(V[v][i].F);
			//printf("%d %d %lf\n", v, V[v][i].F, count(ss, V[v][i].S));
			res+=count(ss, V[v][i].S);
			s+=ss;
		}
	}
	S[v]=s;
	return s;
}

int main()
{
	scanf("%d", &n);
	cons=((double)n*(double)(n-1)*(double)(n-2))/6.0;
	for(int i=0; i<n-1; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V[a].PB(MP(b, c));
		V[b].PB(MP(a, c));
		A[i]=MP(a, b);
		W[i]=c;
	}
	DFS(1);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		int size=min(S[A[a].F], S[A[a].S]);
		res-=count(size, W[a]-b);
		W[a]=b;
		printf("%lf\n", res);
	}
	return 0;
}