#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],pr[N][N],sf[N][N];
long long s;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n+1;j++)
			pr[i][j]=sf[i][j]=0;
		for(int j=1;j<=i;j++)
			pr[i][j]=pr[i][j-1]+(a[j]<a[i]);
		for(int j=n;j>=i;j--)
			sf[i][j]=sf[i][j+1]+(a[j]<a[i]);
	}
	s=0;
	for(int l=1;l<=n;l++)
		for(int r=l+1;r<=n;r++)
			s+=pr[r][l-1]*sf[l][r+1];
	printf("%lld\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}