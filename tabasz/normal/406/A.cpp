#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

bool T[1001];


int main()
{
	int n, m, sum=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int a;
			scanf("%d", &a);
			if(i==j)
			{
				T[i]=a;
				sum+=a;
			}
		}
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int a;
		scanf("%d", &a);
		if(a==3) printf("%d", sum%2);
		else
		{
			int b;
			scanf("%d", &b);
			b--;
			T[b]=(!T[b]);
			if(T[b]) sum++;
			else sum--;
		}
	}
	return 0;
}