#include<bits/stdc++.h>
using namespace std;
int sum[1005];
char a[1005],b[1005];
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	scanf("\n%s\n%s",a+1,b+1);
	for(int i=1;i<=n-m+1;i++)
	{
		bool ok=true;
		for(int j=1;j<=m;j++)
		{
			if(a[i+j-1]!=b[j])
			{
				ok=false;
			}
		}
		sum[i]=sum[i-1];
		if(ok==true)
		{
			sum[i]++;
		}
	}
	int l,r;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&l,&r);
		if(r-l+1<m)
		{
			printf("%d\n",0);
		}
		else
		{
			printf("%d\n",sum[r-m+1]-sum[l-1]);
		}
	}
	return 0;
}