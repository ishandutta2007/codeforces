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
const int M=200000;

int n;
vector<PII> V[400005];
bool B[200005];
int R[200005], in[400005];

void jebaj(int v, int ind)
{
	//printf("lol %d %d\n", v, ind);
	for(int i=V[v].size()-1; i>=0; i--)
	{
		//printf("                 %d %d %d\n", v, V[v][i].F, V[v][i].S);
		if(B[V[v][i].S])
		{
			V[v].pop_back();
			continue;
		}
		else
		{
		//	printf("%d %d %d %d\n", v, V[v][i].F, V[v][i].S, ind);
			in[v]--;
			in[V[v][i].F]--;
			B[V[v][i].S]=1;
			R[V[v][i].S]=ind;
			V[v].pop_back();
			jebaj(V[v][i].F, 1-ind);
			break;
		}
	}
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(MP(b+M, i));
		V[b+M].PB(MP(a, i));
		//printf("qwe %d %d\n", b+n, a);
		in[a]++;
		in[b+M]++;
	}
	for(int i=1; i<=2*M; i++)
		if(in[i]%2==1) jebaj(i, 0);
	for(int i=1; i<=2*M; i++)
		if(in[i]>0) jebaj(i, 0);
	for(int i=1; i<=n; i++)
	{
		if(R[i]) printf("b");
		else printf("r");
	}
	printf("\n");
	return 0;
}