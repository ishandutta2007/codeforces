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
#define pb pop_back

int T[100005];
int P[100005];
int n, pre=0, res, r;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		T[a]=i;
	}
	for(int i=1; i<=n; i++)
	{
		if(T[i]>pre)
			r++;
		else
		{
			res=max(res, r);
			r=1;
		}
		pre=T[i];
	}
	res=max(res, r);
	printf("%d\n", n-res);
	return 0;
}