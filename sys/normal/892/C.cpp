#include <bits/stdc++.h>
using namespace std;
int gcds[2005][2005],done,ans,yes,n,a[2005];
bool prm[2005],tri[2005];
int gcd(int x,int y){if(x<y)swap(x,y);return y==0?x:gcd(y,x%y);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) yes++;
	}
	if(yes){printf("%d",n-yes);return 0;}
	int all=a[1];
	for(int i=1;i<=n;i++)
	{
		gcds[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
			gcds[i][j]=gcd(gcds[i][j-1],a[j]);
	}
	for(int i=2;i<=n;i++)
		all=gcd(all,a[i]);
	if(all!=1){printf("-1");return 0;}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n-j;i++)
			if(gcds[i][i+j]==1){printf("%d",n+j-1);return 0;}
	return 0;
}