#include <bits/stdc++.h>
using namespace std;
const int Maxn=505;
int n,m,a[Maxn][Maxn],b[Maxn][Maxn],cnt1[Maxn],cnt2[Maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),cnt1[i]+=(bool)a[i][j],cnt2[j]+=(bool)a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]),cnt1[i]-=(bool)b[i][j],cnt2[j]-=(bool)b[i][j];
	for(int i=1;i<=n;i++)
		if(cnt1[i]%2)
		{
			printf("No");
			return 0;
		}
	for(int i=1;i<=m;i++)
		if(cnt2[i]%2)
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}