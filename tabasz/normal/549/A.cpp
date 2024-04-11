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

int n, m, res;
char C[55][55], A[4]={'f', 'a', 'c', 'e'};
int T[4];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		scanf("%s", C[i]);
	}
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<m-1; j++)
		{
			for(int k=0; k<4; k++) T[k]=0;
			for(int k=0; k<4; k++)
			{
				if(C[i][j]==A[k]) T[k]++;
				if(C[i+1][j]==A[k]) T[k]++;
				if(C[i][j+1]==A[k]) T[k]++;
				if(C[i+1][j+1]==A[k]) T[k]++;
			}
			bool boo=1;
			for(int k=0; k<4; k++) 
				if(T[k]!=1) boo=0;
			if(boo) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}