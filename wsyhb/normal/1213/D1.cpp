#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=50+5,mx1=2e5+5;
int a[mx],M[mx1][mx],s[mx1];
int main()
{
	int n,k,ans=0x3f3f3f3f;
	scanf("%d%d",&n,&k);
	memset(M,0x3f,sizeof(M));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		int cnt=0;
		while(a[i])
		{
			M[a[i]][i]=cnt;
			cnt++;
			a[i]/=2;
		}
		M[0][i]=cnt;
	}
	for(int i=0;i<=2e5;i++) sort(M[i]+1,M[i]+n+1);
	for(int i=0;i<=2e5;i++)
	{
		int cnt=0;
		bool f=true;
		for(int j=1;j<=k;j++)
		{
			if(M[i][j]>=0x3f3f3f3f)
			{
				f=false;
				break;
			}
			cnt+=M[i][j];
		}
		if(f) ans=min(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}