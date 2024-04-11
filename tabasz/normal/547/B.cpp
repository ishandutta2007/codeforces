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

int n;
int pop=1, maxi=0;
int R[200005];
vector<PII> V;
PII T[200005];

void merge(int p, int k)
{
	T[p]=MP(p, k);
	T[k]=MP(p, k);
	maxi=max(maxi, k-p+1);
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		V.PB(MP(a, i));
	}
	sort(V.begin(), V.end());
	for(int i=n-1; i>=0; i--)
	{
		merge(V[i].S, V[i].S);
		if(T[V[i].S-1].F!=0) merge(T[V[i].S-1].F, V[i].S);
		if(T[V[i].S+1].S!=0) merge(T[V[i].S].F, T[V[i].S+1].S);
		while(pop<=maxi)
		{
			R[pop]=V[i].F;
			pop++;
		}
	}
	for(int i=1; i<=n; i++) printf("%d ", R[i]);
	printf("\n");
	return 0;
}