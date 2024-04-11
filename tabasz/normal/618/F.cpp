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

int n, S[1000005], L[1000005];
vector<PLL> V[2];
bool boo;

void go(int s1, int e1, int s2, int e2)
{
	//printf("%d %d %d %d\n", s1, e1, s2, e2);
	if(boo)
	{
		swap(s1, s2);
		swap(e1, e2);
		swap(V[0], V[1]);
	}
	printf("%d\n", e1-s1);
	for(int i=s1+1; i<=e1; i++)
		printf("%lld ", V[0][i].S);
	printf("\n%d\n", e2-s2);
	for(int i=s2+1; i<=e2; i++)
		printf("%lld ", V[1][i].S);
	printf("\n");
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int j=0; j<2; j++)
	{
		V[j].PB(MP(0, 0));
		for(int i=1; i<=n; i++)
		{
			LL a;
			scanf("%lld", &a);
			V[j].PB(MP(a, i));
		}
		sort(V[j].begin(), V[j].end());
	}
	for(int j=0; j<2; j++)
		for(int i=1; i<=n; i++)
			V[j][i].F+=V[j][i-1].F;
	for(int i=0; i<=n; i++)
		S[i]=-1;
	if(V[0][n].F>V[1][n].F)
	{
		boo=1;
		swap(V[0], V[1]);
	}
	int ind=0;
	//for(int i=0; i<=n; i++)
	//	printf("%d %d\n", V[1][i].F, V[1][i].S);
	for(int i=0; i<=n; i++)
	{
		while(ind<n && V[1][ind+1].F<=V[0][i].F)
			ind++;
		//printf("%d: %d %d: %d\n", i, V[0][i].F, ind, V[1][ind].F);
		L[i]=ind;
		LL r=V[0][i].F-V[1][ind].F;
		//printf("%d: %d %d\n", i, L[i], r);
		if(S[r]!=-1)
		{
			go(S[r], i, L[S[r]], L[i]);
			break;
		}
		else
			S[r]=i;
	}
	return 0;
}