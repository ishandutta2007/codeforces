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

vector<int> D[1000005];
int n, k, q, A[1000005];
LL res, N[200005], S[200005], SO[200005], R[2][1000005];

LL poww(LL a, LL p)
{
	LL r=1;
	int ind=30;
	while(ind>=0)
	{
		r=(r*r)%mod;
		if((p>>ind)%2)
			r=(r*a)%mod;
		ind--;
	}
	return r;
}

void add(int x)
{
	for(int i=(int)D[x].size()-1; i>=0; i--)
	{
		int y=D[x][i];
		LL qwe=N[A[y]+1]-N[A[y]];
		//printf("%d %d %lld\n", x, y, qwe);
		A[y]++;
		if(qwe<0)
			qwe+=mod;
		R[1][y]+=qwe;
		if(R[1][y]>=mod)
			R[1][y]-=mod;
		if(R[1][y]==0)
			continue;
		for(int j=(int)D[y].size()-2; j>=0; j--)
		{
			R[1][D[y][j]]-=R[1][y];
			if(R[1][D[y][j]]<0)
				R[1][D[y][j]]+=mod;
		}
		//printf(" %d %d: %lld\n", x, y, R[1][y]);
		R[0][y]+=R[1][y];
		res+=(R[1][y]*y)%mod;
		if(res>=mod)
			res-=mod;
		if(R[0][y]>=mod)
			R[0][y]-=mod;
		R[1][y]=0;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	for(int i=1; i<=1000000; i++)
		for(int j=i; j<=1000000; j+=i)
			D[j].PB(i);
	scanf("%d%d%d", &n, &k, &q);
	S[0]=1;
	SO[0]=1;
	for(int i=1; i<=n+q; i++)
	{
		S[i]=(S[i-1]*i)%mod;
		SO[i]=poww(S[i], mod-2);
	}
	for(int i=k; i<=n+q; i++)
		N[i]=(((S[i]*SO[i-k])%mod)*SO[k])%mod;
	for(int i=0; i<n+q; i++)
	{
		int a;
		scanf("%d", &a);
		add(a);
		if(i>=n)
			printf("%lld\n", res);
	}
	return 0;
}