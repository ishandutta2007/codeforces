#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define D double
#define LD long double

int n, m, p[2], T[2][1000005], R[1000005];
vector<int> V[2];
D r=0;

void remove(int x, int ind)
{
	if(V[ind][p[ind]]==x)
		p[ind]++;
}

void add(int x, int ind)
{
	while((int)V[ind].size()>p[ind] && T[ind][V[ind][V[ind].size()-1]]<T[ind][x])
		V[ind].pb();
	V[ind].PB(x);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[0][i]=100*a;
	}
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[1][i]=-a;
	}
	int ind=-1;
	for(int i=0; i<n; i++)
	{
		while(ind<i)
		{
			ind++;
			add(ind, 0);
			add(ind, 1);
		}
		int res=min(T[0][V[0][p[0]]], -T[1][V[1][p[1]]]);
		//printf("%d %d: %d %d\n", p[0], p[1], T[0][V[0][p[0]]], -T[1][V[1][p[1]]]);
		while(ind<n-1 && T[0][V[0][p[0]]]<=-T[1][V[1][p[1]]] && T[0][ind+1]<=-T[1][V[1][p[1]]] && -T[1][ind+1]>=T[0][V[0][p[0]]] && T[0][ind+1]<=-T[1][ind+1])
		{
		//	printf("ind=%d\n", ind);
			ind++;
			add(ind, 0);
			add(ind, 1);
			//if(ind>i && )
			res=max(res, min(T[0][V[0][p[0]]], -T[1][V[1][p[1]]]));
		}
		if(ind!=i && T[0][V[0][p[0]]]>-T[1][V[1][p[1]]])
		{
			printf("%d.%d\n", i, ind);
			return 0;
		}
		res=max(res, min(max(T[0][ind+1], T[0][V[0][p[0]]]), -max(T[1][ind+1], T[1][V[1][p[1]]])));
		remove(i, 0);
		remove(i, 1);
		R[i]=res;
	}
	sort(R, R+n);
	//for(int i=0; i<n; i++)
	//	printf("%d ", R[i]);
	//printf("\n");
	D x=(D)m/(D)n;
	for(int i=0; i<=n-m; i++)
	{
	//	printf("%lf ", x*R[i]);
		r+=x*R[i];
		x*=(D)(n-i-m)/(D)(n-i-1);
	}
	printf("%.9lf\n", r);
	return 0;
}