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
const int M=1024*128;
const int inf=1e9;

int n;
bool B[2][100005];
vector<PII> V[2];
PII D[2][2*M];

void add(int q, int v, int val)
{
	B[q][v]=1;
	v+=M;
	D[q][v]=MP(val, val);
	while(v>1)
	{
		v/=2;
		D[q][v].F=min(D[q][2*v].F, D[q][2*v+1].F);
		D[q][v].S=max(D[q][2*v].S, D[q][2*v+1].S);
	}
}

void remove(int q, int v, int val)
{
	B[q][v]=0;
	v+=M;
	D[q][v]=MP(inf, -inf);
	while(v>1)
	{
		v/=2;
		D[q][v].F=min(D[q][2*v].F, D[q][2*v+1].F);
		D[q][v].S=max(D[q][2*v].S, D[q][2*v+1].S);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int q=0; q<2; q++)
	{
		for(int i=1; i<2*M; i++)
		{
			D[q][i].F=inf;
			D[q][i].S=-inf;
		}
	}
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[0].PB(MP(a, b));
		V[1].PB(MP(-a, b));
	}
	sort(V[0].begin(), V[0].end());
	sort(V[1].begin(), V[1].end());
	LL st=0, en=4*1e16, mid=(st+en)/2, r=en;
	while(st<=en)
	{
		bool boo=0;
		for(int q=0; q<2; q++)
		{
			int ind=n-1;
			for(int i=0; i<n; i++)
				if(!B[q][i])
					add(q, i, V[q][i].S);
			LL el=D[q][1].S-D[q][1].F;
			if(el*el<=mid)
			{
				boo=1;
				break;
			}
			for(int i=n-1; i>=0; i--)
			{
				if(V[q][i].F<0)
					break;
				while(ind>=0 && abs(V[q][ind].F)<=V[q][i].F && (LL)(V[q][i].F-V[q][ind].F)*(LL)(V[q][i].F-V[q][ind].F)<=mid)
				{
					remove(q, ind, V[q][ind].S);
					ind--;
				}
				while(ind<i && abs(V[q][ind+1].F)>V[q][i].F)
				{
					ind++;
					add(q, ind, V[q][ind].S);
				}
				LL h=0, l=0;
				if(D[q][1].F!=inf)
				{
					h=max(abs(D[q][1].F), abs(D[q][1].S));
					l=D[q][1].S-D[q][1].F;
				}
				if(D[q][1].F==inf || ((h*h)+((LL)V[q][i].F*(LL)V[q][i].F)<=mid && l*l<=mid))
					boo=1;
				add(q, i, V[q][i].S);
				if(boo)
					break;
			}
			if(boo)
				break;
		}
		if(boo)
		{
			r=min(r, mid);
			en=mid-1;
		}
		else
			st=mid+1;
		mid=(st+en)/2;
	}
	printf("%lld\n", r);
	return 0;
}