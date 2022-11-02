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

int res=0;
vector<PII> V;

int main()
{
	//ios_base:sync_with_stdio(0);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, b));
	}
	for(int i=1; i<m; i++)
	{
		int dist=V[i].F-V[i-1].F, h=abs(V[i].S-V[i-1].S);
		if(dist<h)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
		dist-=h;
		res=max(res, max(V[i].S, V[i-1].S)+dist/2);
	}
	res=max(res, V[0].F+V[0].S-1);
	res=max(res, V[m-1].S+(n-V[m-1].F));
	printf("%d\n", res);
	return 0;
}