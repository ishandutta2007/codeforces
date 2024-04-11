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
const int M=1024*256;

int n;
int R[M], D[2*M];
vector<PII> V;

void add(int v)
{
	//printf("add %d\n", v);
	v+=M;
	D[v]++;
	while(v>1)
	{
		v/=2;
		D[v]=D[2*v]+D[2*v+1];
	}
}

int sum(int p, int k)
{
	p+=M;
	k+=M;
	int r=D[p];
	if(p!=k) r+=D[k];
	while(p/2!=k/2)
	{
		if(p%2==0) r+=D[p+1];
		if(k%2==1) r+=D[k-1];
		p/=2;
		k/=2;
	}
	return r;
}

void jebaj(int ind)
{
	//printf("jebam %d\n", ind);
	for(int i=1; i<n; i++)
	{
		if(i*(ind-1)+2>n) break;
		R[i]+=sum(i*(ind-1)+2, min(i*ind+1, n));
	}
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		V.PB(MP(a, i+1));
	}
	sort(V.begin(), V.end());
	int prev=V[0].F, ind=0;
	for(int i=0; i<n; i++)
	{
		if(V[i].F!=prev)
		{
			for(; ind<i; ind++)
				add(V[ind].S);
			prev=V[i].F;
		}
		jebaj(V[i].S);
	}
	for(int i=1; i<n; i++) printf("%d ", R[i]);
	printf("\n");
	return 0;
}