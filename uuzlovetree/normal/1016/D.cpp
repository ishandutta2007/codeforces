#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,m;
int a[maxn],b[maxn],Ans[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	int s1=0,s2=0;
	for(int i=1;i<=n;++i)s1^=a[i];
	for(int i=1;i<=m;++i)s2^=b[i];
	if(s1!=s2)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)Ans[i][m]=a[i];
	for(int i=1;i<=m;i++)Ans[n][i]=b[i];
	Ans[n][m]=s1^a[n]^b[m];
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)printf("%d ",Ans[i][j]);
		puts("");
	}
	return 0;
}