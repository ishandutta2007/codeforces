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
const int M=1024*1024;

int n, m, R[M], T[M], R2[M];
PII Q[M];
vector<PII> V[M], S;
int D[2*M], dp[M];

void clearr()
{
	for(int i=0; i<2*M; i++)
		D[i]=0;
}

void add(int v, int w)
{
	v+=M;
	D[v]=max(D[v], w);
	while(v>1)
	{
		v/=2;
		D[v]=max(D[2*v], D[2*v+1]);
	}
}


int maxi(int p, int k)
{
	if(p>k)
		return 0;
	p+=M;
	k+=M;
	int r=max(D[p], D[k]);
	while(p/2!=k/2)
	{
		if(p%2==0)
			r=max(r, D[p+1]);
		if(k%2==1)
			r=max(r, D[k-1]);
		p/=2;
		k/=2;
	}
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		S.PB(MP(a, i));
	}
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		S.PB(MP(b, n+i));
		Q[i]=MP(a, b);
	}
	sort(S.begin(), S.end());
	int prev=-1, tmp=0;
	for(int i=0; i<(int)S.size(); i++)
	{
		if(S[i].F!=prev)
		{
			prev=S[i].F;
			tmp++;
		}
		if(S[i].S<n)
			T[S[i].S]=tmp;
		else
			Q[S[i].S-n].S=tmp;
	}
	//for(int i=0; i<n; i++)
	//	printf("%d ", T[i]);
	//printf("\n");
	for(int i=0; i<n; i++)
	{
		dp[i]=1;
		int x=maxi(0, T[i]-1);
		dp[i]+=x;
		add(T[i], x+1);
	}
	clearr();
	for(int i=n-1; i>=0; i--)
	{
		int x=maxi(T[i]+1, M-1);
		dp[i]+=x;
		add(T[i], x+1);
	}
	clearr();
	//for(int i=0; i<n; i++)
	//	printf("%d ", dp[i]);
	//printf("\n");
	for(int i=0; i<n; i++)
	{
		R2[i]=max(R2[i], dp[i]-1);
		R2[i]=max(R2[i], maxi(T[i], M-1));
		add(T[i], dp[i]);
	}
	clearr();
	for(int i=n-1; i>=0; i--)
	{
		R2[i]=max(R2[i], maxi(0, T[i]));
		add(T[i], dp[i]);
	}
	clearr();
	for(int i=0; i<m; i++)
		V[Q[i].F].PB(MP(i, Q[i].S));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<(int)V[i].size(); j++)
		{
			R[V[i][j].F]=1;
			int y=maxi(0, V[i][j].S-1);
			R[V[i][j].F]+=y;
		}
		int x=maxi(0, T[i]-1);
		add(T[i], x+1);
	}
	clearr();
	for(int i=n-1; i>=0; i--)
	{
		for(int j=0; j<(int)V[i].size(); j++)
		{
			int y=maxi(V[i][j].S+1, M-1);
			R[V[i][j].F]+=y;
		}
		int x=maxi(T[i]+1, M-1);
		add(T[i], x+1);
	}
	for(int i=0; i<m; i++)
		printf("%d\n", max(R[i], R2[Q[i].F]));
	return 0;
}