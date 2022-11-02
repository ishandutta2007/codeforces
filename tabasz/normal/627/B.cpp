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
const int M=1024*256;

int n, k, a, b, q;
int D[2][2*M], T[M];

void add(int v)
{
	v+=M;
	D[0][v]=min(a, T[v-M]);
	D[1][v]=min(b, T[v-M]);
	while(v>1)
	{
		v/=2;
		D[0][v]=D[0][2*v]+D[0][2*v+1];
		D[1][v]=D[1][2*v]+D[1][2*v+1];
	}
}

int sum(int p, int k, int ind)
{
	if(p>k)
		return 0;
	p+=M;
	k+=M;
	int r=D[ind][p];
	if(p!=k)
		r+=D[ind][k];
	while(p/2!=k/2)
	{
		if(p%2==0)
			r+=D[ind][p+1];
		if(k%2==1)
			r+=D[ind][k-1];
		p/=2;
		k/=2;
	}
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%d%d", &n, &k, &b, &a, &q);
	for(int i=0; i<q; i++)
	{
		int a, b, c;
		scanf("%d%d", &a, &b);
		if(a==1)
		{
			scanf("%d", &c);
			T[b]+=c;
			add(b);
		}
		else
			printf("%d\n", sum(1, b-1, 0)+sum(b+k, n, 1));
	}
	return 0;
}