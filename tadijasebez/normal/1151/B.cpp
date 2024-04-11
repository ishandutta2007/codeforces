#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,pos=-1;
	vector<vector<int>> a;
	scanf("%i %i",&n,&m);
	a.assign(n+1,vector<int>(m+1,0));
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		scanf("%i",&a[i][j]);
		if(a[i][j]!=a[i][1]) pos=i*1000+j;
	}
	int xr=0;
	for(i=1;i<=n;i++) xr^=a[i][1];
	if(xr!=0 || pos!=-1)
	{
		printf("TAK\n");
		if(xr!=0) for(i=1;i<=n;i++) printf("1 ");
		else for(i=1;i<=n;i++) printf("%i ",i==pos/1000?pos%1000:1);
	}
	else printf("NIE\n");
	return 0;
}