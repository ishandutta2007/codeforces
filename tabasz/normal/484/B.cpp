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

int T[2000005];
bool B[2000005];

int main()
{
	int n, res=0, maxi=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		B[a]=1;
		maxi=max(maxi, a);
	}
	T[0]=2000000;
	for(int i=1; i<=min(2*maxi, 2000000); i++)
	{
		if(B[i-1]) T[i]=1;
		else T[i]=T[i-1]+1;
	}
	//for(int i=1; i<=maxi; i++) printf("%d\n", B[i]);
	for(int i=1; i<=maxi; i++)
	{
		if(B[i])
		{
			for(int j=i+i; j<=min(2*maxi, 2000000); j+=i)
			{
				res=max(res, i-T[j]);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}