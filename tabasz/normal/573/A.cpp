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

int n;
int T[100005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		while(a%2==0)
			a/=2;
		while(a%3==0)
			a/=3;
		T[i]=a;
	}
	for(int i=1; i<n; i++)
	{
		if(T[i]!=T[i-1])
		{
			printf("No\n");
			return 0;
		}
	}	
	printf("Yes\n");
	return 0;
}