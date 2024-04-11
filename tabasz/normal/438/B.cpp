#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

int A[100005], tmp[100005];
pair<int, int> T[100005], F[100005];
vector<int> V[100005];
vector<pair<int, int> > W;
D res;
bool B[100005];

int find(int a)
{
	if(F[a].F==a) return a;
	else return F[a].F=find(F[a].F);
}

void onion(int a, int b)
{
	a=find(a);
	b=find(b);
	F[a].S+=F[b].S;
	F[b].F=a;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		A[i]=a;
		T[i]=MP(A[i], i);
	}
	sort(T, T+n);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i=0; i<n; i++) tmp[i]=n;
	for(int i=0; i<n; i++) F[i]=MP(i, 1);
	for(int i=n-1; i>=0; i--)
	{
		//printf("t: %d %d\n", T[i].F, T[i].S);
		W.clear();
		for(int j=0; j<V[T[i].S].size(); j++)
		{
			int v=V[T[i].S][j], o=find(v);
			if(B[v] && tmp[o]>i)
			{
				tmp[o]=i;
				W.PB(MP(o, F[o].S));
			}
		}
		W.PB(MP(T[i].S, 1));
		LL s=0;
		for(int j=0; j<W.size(); j++)
		{
		//	printf("%d %d\n", W[j].F, W[j].S);
			s+=(LL)W[j].S;
		}
		//printf("\n");
		s*=s;
		for(int j=0; j<W.size(); j++) s-=(LL)W[j].S*(LL)W[j].S;
		s*=(LL)A[T[i].S];
		res+=(D)s/(D)((LL)n*(LL)(n-1));
		for(int j=1; j<W.size(); j++) onion(W[j-1].F, W[j].F);
		B[T[i].S]=1;
	}
	//D sc=(D)res/(D)(n*(n-1));
	printf("%lf\n", res);
	return 0;
}