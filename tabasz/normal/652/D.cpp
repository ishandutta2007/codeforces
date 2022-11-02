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
const int M=1024*512;

int n;
int D[2*M], S[M], R[M];
vector<PII> V;

void add(int v)
{
	v+=M;
	D[v]=1;
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
	if(p!=k)
		r+=D[k];
	while(p/2!=k/2)
	{
		if(p%2==0)
			r+=D[p+1];
		if(k%2==1)
			r+=D[k-1];
		p/=2;
		k/=2;
	}
	return r;
}


int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, -i));
		V.PB(MP(b, i));
	}
	sort(V.begin(), V.end());
	int prev=-1000000001, tmp=0;
	for(int i=0; i<(int)V.size(); i++)
	{
		if(V[i].F!=prev)
		{
			prev=V[i].F;
			tmp++;
		}
		V[i].F=tmp;
		if(V[i].S<0)
			S[-V[i].S]=tmp;
		else
		{
			R[V[i].S]=sum(S[V[i].S], V[i].F);
			add(S[V[i].S]);
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d\n", R[i]);
	return 0;
}