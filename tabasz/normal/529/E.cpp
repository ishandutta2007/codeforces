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

int n, k, q, T[100005];
map<int, int> M;

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
	{
		scanf("%d", T+i);
		int x=0;
		for(int j=1; j<=k; j++)
		{
			x+=T[i];
			if(M[x]!=0) M[x]=min(M[x], j);
			else M[x]=j;
		}
	}
	scanf("%d", &q);
	for(int i=0; i<q; i++)
	{
		int a;
		int res=1000000;
		scanf("%d", &a);
		for(int j=0; j<n; j++)
		{
			int x=0;
			for(int l=1; l<=k; l++)
			{
				x+=T[j];
				if(x==a) res=min(res, l);
				if(M[a-x]!=0) res=min(res, M[a-x]+l);
			}
		}
		if(res<=k) printf("%d\n", res);
		else printf("-1\n");
	}
	return 0;
}