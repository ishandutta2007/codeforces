#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
const LL mod=1e9+7;


int n, k;
bool vis[1000006];
int T[1000006], A[1000006];
vector<int> V;
LL res=1;

int DFS(int v)
{
	vis[v]=1;
	int x=1;
	if(!vis[((LL)v*(LL)k)%n])
		x+=DFS(((LL)v*(LL)k)%n);
	return x;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	if(k==0)
	{
		LL r=1;
		for(int i=1; i<n; i++)
			r=(r*n)%mod;
		printf("%d\n", (int)r);
		return 0;
	}
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
		{
			int l=DFS(i);
			V.PB(l);
			T[l]++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(T[i]>0)
		{
			int x=i;
			while(x<=n)
			{
				A[x]+=i*T[i];
				if(A[x]>=mod)
					A[x]-=mod;
				x+=i;
			}
		}
	}
	for(int i=0; i<(int)V.size(); i++)
		res=(res*A[V[i]])%mod;
	printf("%d\n", (int)res);
	return 0;
}