#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull a[5005];
ull f[5005][5005];
int main()
{
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%I64d",&a[i]);
		f[0][i]=a[i];
	}
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<m-i;j++)
		{
			f[i][j]=f[i-1][j+1]^f[i-1][j];
		}
	}
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<m-i;j++)
		{
			f[i][j]=max(f[i][j],max(f[i-1][j],f[i-1][j+1]));
		}
	}
	int n;
	cin>>n;
	int l,r;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",f[r-l][l-1]);
	}
	return 0;
}