#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[55][55],b[55][55];
bool vis[55][55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)scanf("%d",&b[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)if(a[i][j]>b[i][j])swap(a[i][j],b[i][j]);
	bool yes=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1]&&b[i][j]>b[i-1][j]&&b[i][j]>b[i][j-1])continue;
			yes=0;
		}
	if(yes)puts("Possible");
	else puts("Impossible");
	return 0;
}