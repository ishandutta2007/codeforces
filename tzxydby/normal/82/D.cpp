#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int f[N][N],a[N],n;
inline void chmin(int &a,int b)
{
	if(a>b) a=b;
}
int dp(int i,int j)
{
	if(f[i][j])
		return f[i][j];
	if(j==0)
		return f[i][j]=a[i];
	if(j==1)
		return f[i][j]=max(a[i],a[j]);
	f[i][j]=min(dp(j,j-2)+max(a[i],a[j-1]),dp(j-1,j-2)+max(a[i],a[j]));
	chmin(f[i][j],dp(i,j-2)+max(a[j],a[j-1]));
	return f[i][j];
}
void path(int i,int j)
{
	if(j==0)
		printf("%d\n",n-i+1);
	else if(j==1)
		printf("%d %d\n",n-i+1,n-j+1);
	else if(f[i][j]==f[j][j-2]+max(a[i],a[j-1]))
	{
		printf("%d %d\n",n-i+1,n-j+2);
		path(j,j-2);
	} 
	else if(f[i][j]==f[i][j-2]+max(a[j],a[j-1]))
	{
		printf("%d %d\n",n-j+1,n-j+2);
		path(i,j-2);
	} 
	else 
	{
		printf("%d %d\n",n-i+1,n-j+1);
		path(j-1,j-2);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[n-i]);
	printf("%d\n",dp(n,n-1));
	path(n,n-1);
	return 0;
}