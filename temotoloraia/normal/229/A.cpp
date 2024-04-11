#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[110][10010];
int b[110][10010],n,m,i,j,ans,c;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++) b[i][j]=1000000;
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		for(j=0;j<2*m;j++)
			if(a[i][j%m]=='1') b[i][j%m]=0; else b[i][j%m]=b[i][(j-1+m)%m]+1;
		for(j=2*m-1;j>=0;j--)
			b[i][j%m]=min(b[i][j%m],b[i][(j+1)%m]+1);
	}
	ans=1000000;
	for(j=0;j<m;j++)
	{
		for(i=1,c=0;i<=n;i++) c+=b[i][j];
		ans=min(ans,c);
	}
	if(ans==1000000) puts("-1"); else cout<<ans<<endl;
	return 0;
}