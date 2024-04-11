#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=100005,maxN=505;
int n,l,k,ans;
int a[maxn],b[maxn],c[maxn],f[maxN][maxN];
string s;
int main(){
	scanf("%d%d%d",&n,&l,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	memset(f,0x3f,sizeof(f)),ans=f[0][0];
	f[1][0]=0;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int p=0;p<=j&&p<(i-1);p++)
				f[i][j]=min(f[i][j],f[i-p-1][j-p]+b[i-p-1]*(a[i]-a[i-p-1]));
	for(int i=n;i>=n-k&&i>=1;i--)
		for(int j=0;j<=k-(n-i);j++)
			ans=min(ans,f[i][j]+b[i]*(l-a[i]));
	printf("%d\n",ans);
	return 0;
}