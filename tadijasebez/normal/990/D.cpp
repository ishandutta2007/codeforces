#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=1050;
int mat[N][N];
int main()
{
	int n,a,b,i,j;
	scanf("%i %i %i",&n,&a,&b);
	if(a>1 && b>1) return printf("NO\n"),0;
	if(n==2 && a==1 && b==1) return printf("NO\n"),0;
	if(a==1 && b==1)
	{
		if(n==3) return printf("NO\n"),0;
		for(i=1;i<n;i++) mat[i][i+1]=1,mat[i+1][i]=1;
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%i",mat[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	if(a==1)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j) mat[i][j]=1;
			}
		}
		for(i=b+1;i<=n;i++) 
		{
			mat[1][i]=mat[i][1]=0;
		}
	}
	else
	{
		for(i=a+1;i<=n;i++) 
		{
			mat[1][i]=mat[i][1]=1;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%i",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}