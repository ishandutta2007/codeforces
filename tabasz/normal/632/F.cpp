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

bitset<2501> A[2501];
vector<PII> V;
int T[2505][2505], n;

bool cmp(PII a, PII b)
{
	if(T[a.F][a.S]==T[b.F][b.S])
		return a<b;
	return T[a.F][a.S]<T[b.F][b.S];
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", T[i]+j);
			V.PB(MP(i, j));
		}
	}
	for(int i=0; i<n; i++)
	{
		if(T[i][i]!=0)
		{
			printf("NOT MAGIC\n");
			return 0;
		}
		for(int j=0; j<n; j++)
		{
			if(T[i][j]!=T[j][i])
			{
				printf("NOT MAGIC\n");
				return 0;
			}
		}
	}
	sort(V.begin(), V.end(), cmp);
	int prev=-1;
	vector<PII> X;
	for(int i=0; i<(int)V.size(); i++)
	{
		if(T[V[i].F][V[i].S]!=prev)
		{
			while(!X.empty())
			{
				A[X[X.size()-1].F][X[X.size()-1].S]=1;
				X.pb();
			}
			prev=T[V[i].F][V[i].S];
		}
		X.PB(V[i]);
		if((A[V[i].F]&A[V[i].S]).any())
		{
			printf("NOT MAGIC\n");
			return 0;
		}
	}
	printf("MAGIC\n");
	return 0;
}