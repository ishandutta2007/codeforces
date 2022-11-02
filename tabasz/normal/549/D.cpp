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
char C[101][101];
int A[101][101];
int T[101][101];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%s", C[i]);
	for(int i=n-1; i>=0; i--)
	{
		for(int j=m-1; j>=0; j--)
		{
			if(C[i][j]=='W') A[i][j]=1;
			else A[i][j]=-1;
		}
	}
	for(int i=n-1; i>=0; i--)
	{
		for(int j=m-1; j>=0; j--)
		{
			int s=A[i+1][j]+A[i][j+1]-A[i+1][j+1];
			if(s!=A[i][j]) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}