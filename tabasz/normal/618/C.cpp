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
#define PPLL pair<PLL, int> 

int n;
vector<PPLL> V;

LL dist(PPLL a)
{
	return a.F.F*a.F.F+a.F.S*a.F.S;
}

LL il(PPLL a, PPLL b)
{
	return a.F.F*b.F.S-a.F.S*b.F.F;
}

bool cmp(PPLL a, PPLL b)
{
	if(a.F.S>=0 && b.F.S<0)
		return true;
	if(b.F.S>=0 && a.F.S<0)
		return false;
	if(a.F.S==0 && b.F.S==0)
	{
		if(a.F.F>0 && b.F.S<0)
			return true;
		if(b.F.F>0 && a.F.S<0)
			return false;
		return abs(a.F.F)<abs(b.F.F);
	}
	if(il(a, b)==0)
		return dist(a)<dist(b);
	return il(a, b)>0;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(MP(b, a), i+1));
	}
	sort(V.begin(), V.end());
	for(int i=0; i<n; i++)
		swap(V[i].F.F, V[i].F.S);
	for(int i=1; i<n; i++)
	{
		V[i].F.F-=V[0].F.F;
		V[i].F.S-=V[0].F.S;
	}
	sort(V.begin()+1, V.end(), cmp);
	int ind=2;
	while(il(V[1], V[ind])==0)
		ind++;
	printf("%d %d %d\n", V[0].S, V[1].S, V[ind].S);
	return 0;
}