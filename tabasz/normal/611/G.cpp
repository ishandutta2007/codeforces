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
const LL mod=1e9+7;

int n;
vector<PII> V;
LL area, res;
PLL P[1000005];

LL il(int a, int b, int c)
{
	return (LL)(V[a].F-V[c].F)*(V[b].S-V[c].S)-(LL)(V[a].S-V[c].S)*(V[b].F-V[c].F);
}

PLL getsum(int en, int st)
{
	PLL x=MP(P[en].F-P[st].F-((LL)V[st].F*(en-st))%mod, P[en].S-P[st].S-((LL)V[st].S*(en-st))%mod);
	while(x.F<0)
		x.F+=mod;
	while(x.S<0)
		x.S+=mod;
	while(x.F>=mod)
		x.F-=mod;
	while(x.S>=mod)
		x.S-=mod;
	return x;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
	}
	for(int i=0; i<n; i++)
		V.PB(V[i]);
	P[0]=V[0];
	for(int i=1; i<2*n; i++)
	{
		P[i]=MP(P[i-1].F+V[i].F, P[i-1].S+V[i].S);
		if(P[i].F>=mod)
			P[i].F-=mod;
		if(P[i].S>=mod)
			P[i].S-=mod;
		if(P[i].F<0)
			P[i].F+=mod;
		if(P[i].S<0)
			P[i].S+=mod;
	}
	for(int j=2; j<n; j++)
		area=area+il(j, j-1, 0);
	int tmp=1;
	LL tmpa=0, asum=0;
	for(int i=0; i<n; i++)
	{
		LL asd=il(tmp+1, tmp, i);
		while(tmp+1<i+n && (tmpa+asd<(area+1)/2 || (area%2==0 && tmpa+asd==area/2 && tmp+1<n)))
		{
			tmpa+=asd;
			//printf("%d %d %lld %lld\n", i, tmp+1, tmpa, area);
			asum=(asum+tmpa)%mod;
			tmp++;
			asd=il(tmp+1, tmp, i);
		}
		res-=2*asum;
		while(res<0)
			res+=mod;
		tmpa-=il(tmp, i+1, i);
		PLL x=getsum(tmp, i+1);
		//printf("         %d %d %lld\n", i, tmp, asum);
		PLL y=MP(V[i].F-V[i+1].F, V[i].S-V[i+1].S);
		asum-=(y.F*x.S)%mod-(y.S*x.F)%mod;
		while(asum<0)
			asum+=mod;
		while(asum>=mod)
			asum-=mod;
	//	printf("%d %d %d\n", i, tmp, asum);
	}
	area%=mod;
	LL diag=(((LL)n*(n-3))/2)%mod;
	//printf("%d\n", area*diag);
	res=(res+area*diag)%mod;
	printf("%d\n", (int)res);
	return 0;
}