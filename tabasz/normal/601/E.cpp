#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const int M=1024*32;
const LL p=1e7+19;
const LL q=1e9+7;

int n, k, querry, tmp;
int BP[20][1001];
vector<int> D[2*M];
bool Q[M];
PII T[M];
int S[M], E[M];
LL P[M];

void add(int v, int vp, int vk, int p, int k, int w)
{
	if(vp>=p && vk<=k)
	{
		D[v].PB(w);
		return;
	}
	if(vp>k || vk<p)
		return;
	int mid=(vp+vk)/2;
	add(2*v, vp, mid, p, k, w);
	add(2*v+1, mid+1, vk, p, k, w);
}

void printres(int lev)
{
	LL best=0, res=0;
	for(int i=1; i<=k; i++)
	{
		best=max(best, (LL)BP[lev][i]);
		res+=(best*P[i-1])%q;
		if(res>=q)
			res-=q;
	}
	printf("%d\n", (int)res);
}

void go(int v, int lev)
{
	for(int i=0; i<(int)D[v].size(); i++)
		for(int j=k; j-T[D[v][i]].S>=0; j--)
			BP[lev][j]=max(BP[lev][j], BP[lev][j-T[D[v][i]].S]+T[D[v][i]].F);
	if(v<M)
	{
		for(int i=0; i<=k; i++)
			BP[lev+1][i]=BP[lev][i];
		go(2*v, lev+1);
		for(int i=0; i<=k; i++)
			BP[lev+1][i]=BP[lev][i];
		go(2*v+1, lev+1);
	}
	if(v>=M && Q[v-M])
		printres(lev);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	P[0]=1;
	for(int i=1; i<=k; i++)
		P[i]=(P[i-1]*p)%q;
	for(int i=1; i<=k; i++)
		BP[0][i]=-2000000000;
	tmp=n;
	for(int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		T[i]=MP(a, b);
		S[i]=0;
		E[i]=M-1;
	}
	scanf("%d", &querry);
	for(int i=1; i<=querry; i++)
	{
		int x, a, b;
		scanf("%d", &x);
		if(x==1)
		{
			scanf("%d%d", &a, &b);
			tmp++;
			T[tmp]=MP(a, b);
			S[tmp]=i;
			E[tmp]=M-1;
		}
		if(x==2)
		{
			scanf("%d", &a);
			E[a]=i;
		}
		if(x==3)
			Q[i]=1;
	}
	for(int i=1; i<=tmp; i++)
		add(1, 0, M-1, S[i], E[i], i);
	go(1, 0);
	return 0;
}