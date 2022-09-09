#include <bits/stdc++.h>
using namespace std;
const int N=1050;
char base[N][N];
int r[N],c[N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	int all=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",base[i]+1);
		for(j=1;j<=m;j++) if(base[i][j]=='*') r[i]++,c[j]++,all++;
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		int cnt=c[j]+r[i]-(base[i][j]=='*');
		if(cnt==all)
		{
			printf("YES\n%i %i\n",i,j);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}