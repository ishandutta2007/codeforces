#include <stdio.h>
#define ll long long
const int N=505;
int node[N],dist[N][N],a[N][N];
ll sol[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%i",&a[i][j]);
	for(i=n;i;i--) scanf("%i",&node[i]);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dist[i][j]=a[node[i]][node[j]];
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j]=dist[i][k]+dist[k][j];
		for(i=1;i<=k;i++) for(j=1;j<=k;j++) sol[n-k+1]+=dist[i][j];
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);printf("\n");
	return 0;
}