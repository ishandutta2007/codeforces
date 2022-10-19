#include<bits/stdc++.h>
using namespace std;
int q,n,a[2][200010];
bool f[2][200010][3];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%1d",&a[0][i]);
		for(int i=1;i<=n;i++) scanf("%1d",&a[1][i]);
		if(a[0][1]==1||a[0][1]==2) f[0][1][0]=1;
		else f[0][1][2]=1;
		if(a[1][1]!=1&&a[1][1]!=2)
		{
			if(f[0][1][2]) f[1][1][0]=1; 
		}
		for(int i=2;i<=n;i++)
		{
			if(a[0][i]==1||a[0][i]==2)
			{
				if(f[0][i-1][0]) f[0][i][0]=1;
			}
			else
			{
				if(f[0][i-1][0]) f[0][i][2]=1;
			}
			if(a[1][i]==1||a[1][i]==2)
			{
				if(f[1][i-1][0]) f[1][i][0]=1;
			}
			else
			{
				if(f[1][i-1][0]) f[1][i][1]=1;
				if(f[0][i][2]) f[1][i][0]=1;
			}
			if(f[1][i][1]&&a[0][i]!=1&&a[0][i]!=2) f[0][i][0]=1;
		}
		if(f[1][n][0]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}