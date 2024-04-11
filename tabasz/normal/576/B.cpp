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

int n, tmp;
PII A[100005];
int T[100005];
vector<int> V[100005];
bool vis[100005];

void DFS(int v)
{
	V[tmp].PB(v);
	vis[v]=1;
	if(!vis[T[v]])
		DFS(T[v]);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", T+i+1);
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			DFS(i);
			A[tmp]=MP((int)V[tmp].size(), tmp);
			//printf("%d %d\n", tmp, A[tmp].F);
			tmp++;
		}
	}
	sort(A, A+tmp);
	if((int)V[A[0].S].size()>2)
	{
		printf("NO\n");
		return 0;
	}
	if((int)V[A[0].S].size()==1)
	{
		printf("YES\n");
		for(int i=1; i<=n; i++)
			if(i!=V[A[0].S][0])
				printf("%d %d\n", i, V[A[0].S][0]);
		return 0;
	}
	for(int i=0; i<tmp; i++)
	{
		if((int)V[A[i].S].size()%2)
		{
			printf("NO\n");
			return 0;
		}
	}
	//printf("lol %d\n", (int)V[A[0].S].size());
	printf("YES\n%d %d\n", V[A[0].S][0], V[A[0].S][1]);
	for(int i=1; i<tmp; i++)
		for(int j=0; j<(int)V[A[i].S].size(); j++)
				printf("%d %d\n", V[A[0].S][j%2], V[A[i].S][j]);
	return 0;
}