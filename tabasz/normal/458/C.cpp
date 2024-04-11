#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<math.h>
#include<map>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
const int M=16384;
const int M2=131072;

int n, my, best;
pair<int, int> T[2*M2];
pair<int, int> D[2*M];
vector<int> V[100005];
int res=2000000001;

void add(int v, int w)
{
	v+=M;
	D[v].S+=w;
	D[v].F=(v-M)*D[v].S;
	while(v>1)
	{
		v/=2;
		D[v].F=D[2*v+1].F+D[2*v].F;
		D[v].S=D[2*v+1].S+D[2*v].S;
	}
}

void add2(int v, int w)
{
	v+=M2;
	T[v].F+=w;
	T[v].S=v-M2;
	while(v>1)
	{
		v/=2;
		if(T[2*v].F>T[2*v+1].F) T[v]=T[2*v];
		else T[v]=T[2*v+1];
	}
}

int sum(int x)
{
	int v=1, s=0;
	while(v<M)
	{
		if(D[2*v].S<=x)
		{
			x-=D[2*v].S;
			s+=D[2*v].F;
			v=2*v+1;
		}
		else v*=2;
	}
	s+=x*(v-M);
	return s;
}

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==0 || b==0) my++;
		else
		{
			add2(a, 1);
			V[a].PB(b);
			add(b, 1);
		}
	}
	for(int i=0; i<100005; i++)
	{
		sort(V[i].begin(), V[i].end(), cmp);
		best=max(best, (int)V[i].size());
	}
	if(my>best)
	{
		printf("0\n");
		return 0;
	}
	res=sum(best-my+1);
	int tmp=0;
	for(int i=best-1; i>=my; i--)
	{
		int r=0;
		while(T[1].F>i)
		{
			//printf(" %d\n", T[1].F);
			tmp+=V[T[1].S][V[T[1].S].size()-1];
			my++;
			add(V[T[1].S][V[T[1].S].size()-1], -1);
			V[T[1].S].pop_back();
			add2(T[1].S, -1);
		}
		if(my<=i) r+=sum(i-my+1);
		r+=tmp;
		res=min(r, res);
	}
	cout<< res << '\n';
	return 0;
}