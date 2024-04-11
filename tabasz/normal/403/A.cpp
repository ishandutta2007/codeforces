#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

bool T[25][25];

int main()
{
	int t;
	scanf("%d", &t);
	while(t)
	{
		int n, p;
		scanf("%d%d", &n, &p);
		for(int i=1; i<n; i++) T[i][i+1]=1;
		T[n][1]=1;
		for(int i=1; i<n-1; i++) T[i][i+2]=1;
		T[n-1][1]=1;
		T[n][2]=1;
		int li=3;
		while(p)
		{
			for(int i=1; i<=n; i++)
			{
				if(p==0) break;
				int j=i+li;
				if(j>n) j-=n;
				if(!T[i][j] && !T[j][i])
				{
					T[i][j]=1;
					p--;
				}
			}
			li++;
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i!=j && (T[i][j] || T[j][i]))
				{
					T[i][j]=0;
					T[j][i]=0;
					printf("%d %d\n", i, j);
				}
			}
		}
		t--;
	}
	return 0;
}