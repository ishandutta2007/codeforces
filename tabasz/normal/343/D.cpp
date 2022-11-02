#include<cstdio>
#include<algorithm>
#include<vector>
#include<math.h>
#include<set>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PII pair<int, int>
#define PB push_back
const int M=1024*512;

struct node
{
	int par, pre, post, path, place, size;
	vector<int> E;
};

vector<int> V[M], P[M], D[M];
node T[M];
int n, q, time=-1, pathtmp=1, D2[2*M], m[M];
bool vis[M];

int getpow(int x)
{
	int i=1;
	while(i<x) i*=2;
	return i;
}

int DFS(int v, int prev)
{
	vis[v]=1;
	time++;
	T[v].pre=time;
	T[v].par=prev;
	int s=1;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i]])
		{
			T[v].E.PB(V[v][i]);
			s+=DFS(V[v][i], v);
		}
	}
	T[v].size=s;
	T[v].post=time;
	return s;
}

void DFS2(int v, int pathnum, int pathpl)
{
	T[v].path=pathnum;
	T[v].place=pathpl;
	P[pathnum].PB(v);
	PII x=MP(0, -1);
	for(int i=0; i<(int)T[v].E.size(); i++)
		if(T[T[v].E[i]].size>x.F)
			x=MP(T[T[v].E[i]].size, i);
	for(int i=0; i<(int)T[v].E.size(); i++)
	{
		if(i==x.S)
			DFS2(T[v].E[i], pathnum, pathpl+1);
		else
			DFS2(T[v].E[i], pathtmp++, 0);
	}
}

void maketrees()
{
	for(int i=0; i<pathtmp; i++)
	{
		D[i].resize(getpow((int)P[i].size())*2, -1);
		m[i]=getpow((int)P[i].size());
	}
}

void add(int ind, int v, int t)
{
	v+=m[ind];
	D[ind][v]=t;
	while(v>1)
	{
		v/=2;
		D[ind][v]=max(D[ind][2*v], D[ind][2*v+1]);
	}
}

void add2(int v, int t)
{
	v+=M;
	D2[v]=t;
	while(v>1)
	{
		v/=2;
		D2[v]=max(D2[2*v], D2[2*v+1]);
	}
}

int maxi2(int p, int k)
{
	p+=M;
	k+=M;
	int r=max(D2[p], D2[k]);
	while(p/2!=k/2)
	{
		if(p%2==0) r=max(r, D2[p+1]);
		if(k%2==1) r=max(r, D2[k-1]);
		p/=2;
		k/=2;
	}
	return r;
}

int maxi(int ind, int p, int k)
{
	p+=m[ind];
	k+=m[ind];
	int r=max(D[ind][p], D[ind][k]);
	while(p/2!=k/2)
	{
		if(p%2==0) r=max(r, D[ind][p+1]);
		if(k%2==1) r=max(r, D[ind][k-1]);
		p/=2;
		k/=2;
	}
	return r;
}

int maxii(int v)
{
	int r=-1;
	while(v!=0)
	{
		r=max(r, maxi(T[v].path, 0, T[v].place));
		v=T[P[T[v].path][0]].par;
	}
	return r;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	DFS(1, 0);
	DFS2(1, 0, 0);
/*	for(int i=1; i<=n; i++)
	{
		printf("%d: %d %d %d %d %d %d\n", i, T[i].par, T[i].pre, T[i].post, T[i].path, T[i].place, T[i].size);
	}*/
	maketrees();
	scanf("%d", &q);
	for(int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==1)
		{
		//	printf("1 %d %d %d\n", T[b].path, T[b].place, i);
			add(T[b].path, T[b].place, i);
		}
		if(a==2)
		{
		//	printf("2 %d %d\n", T[b].pre, i);
			add2(T[b].pre, i);
		}	
		if(a==3)
		{
		//	printf("lol %d %d %d %d %d\n", maxi2(T[b].pre, T[b].post), maxii(b), T[b].pre, T[b].post, b);
			if(maxi2(T[b].pre, T[b].post)>maxii(b)) printf("0\n");
			else printf("1\n");
		}
	}
	return 0;
}