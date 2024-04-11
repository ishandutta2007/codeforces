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

int n;
int T[200002];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		T[i]=a+i;
	}
	sort(T, T+n);
	for(int i=0; i<n-1; i++)
	{
		if(T[i]==T[i+1])
		{
			printf(":(\n");
			return 0;
		}
	}
	for(int i=0; i<n; i++) printf("%d ", T[i]-i);
	printf("\n");
	return 0;
}