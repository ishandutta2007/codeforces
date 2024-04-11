#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[705],root[705][705];
bool f[705][705][2];
int gcd(int x,int y)
{
	if(x>y)return gcd(y,x);
	if(x==0)return y;
	return gcd(y%x,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	f[1][1][1]=gcd(a[1],a[2])>1;
	f[n][n][0]=gcd(a[n-1],a[n])>1;
	for(int i=2;i<n;i++)
	{
		f[i][i][0]=gcd(a[i-1],a[i])>1;
		f[i][i][1]=gcd(a[i],a[i+1])>1;
	}
	for(int i=1;i<=n+1;i++)
	  f[i][i-1][0]=f[i][i-1][1]=1;
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int k=l;k<=r;k++)
			if(f[l][k-1][1]&&f[k+1][r][0])
			{
				if(gcd(a[k],a[l-1])>1)f[l][r][0]=1;
				if(gcd(a[k],a[r+1])>1)f[l][r][1]=1;
				if(f[l][r][0]&&f[l][r][1])break;
			}
		}
	}
	if(f[1][n][0]||f[1][n][1])printf("Yes\n");
	else printf("No\n");
	return 0;
}