#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=105;
int sol[N][N],a[N],b[N];
bool Check(int n, int m)
{
	//return 1;
	int i,j;
	for(i=1;i<=n;i++)
	{
		int x=0;
		for(j=1;j<=m;j++) x^=sol[i][j];
		if(x!=a[i]) return 0;
	}
	for(j=1;j<=m;j++)
	{
		int x=0;
		for(i=1;i<=n;i++) x^=sol[i][j];
		if(x!=b[j]) return 0;
	}
	return 1;
}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=m;i++) scanf("%i",&b[i]);
	for(i=1;i<n;i++) sol[i][m]=a[i];
	for(i=1;i<m;i++) sol[n][i]=b[i];
	int x=0;
	for(i=1;i<n;i++) x^=a[i];
	x^=b[m];
	sol[n][m]=x;
	if(Check(n,m))
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++) printf("%i ",sol[i][j]);
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}