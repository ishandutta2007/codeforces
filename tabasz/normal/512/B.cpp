#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

int n, dp[1100], res=1000000000, pot[20];
PII T[303];
vector<int> V[303], P;
bool A[100001];

void sito()
{
	for(int i=2; i<=32000; i++)
	{
		if(A[i]==0)
		{
			P.PB(i);
			int x=i+i;
			while(x<=32000)
			{
				A[x]=1;
				x+=i;
			}
		}
	}
}

void jebaj(int ind)
{
	int asd=pot[V[ind].size()]-1;
	dp[asd]=T[ind].S;
	for(int i=0; i<asd; i++) dp[i]=1000000000;
	for(int i=ind+1; i<n; i++)
	{
		int tmp=0;
		for(int j=0; j<(int)V[ind].size(); j++) if(T[i].F%V[ind][j]==0) tmp+=pot[j];
		for(int j=asd; j>0; j--) dp[j&tmp]=min(dp[j&tmp], dp[j]+T[i].S);
	}
	res=min(res, dp[0]);
}

int main()
{
	//ios_base:sync_with_stdio(0);
	pot[0]=1;
	sito();
	for(int i=1; i<20; i++) pot[i]=pot[i-1]*2;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i].F=a;
		for(int j=0; j<(int)P.size(); j++)
		{
			if(a==1) break;
			if(a%P[j]==0)
			{
				V[i].PB(P[j]);
				while(a%P[j]==0) a/=P[j];
			}
		}
		if(a>1) V[i].PB(a);
	}
	for(int i=0; i<n; i++)
	{
		//for(int j=0; j<(int)V[i].size(); j++) printf("%d qwe", V[i][j]);
		//printf("\n");
		int a;
		scanf("%d", &a);
		T[i].S=a;
	}
	for(int i=0; i<n; i++) jebaj(i);
	if(res<1000000000) printf("%d\n", res);
	else printf("-1\n");
	return 0;
}