#include<bits/stdc++.h>
using namespace std;
int l[10000];
int r[10000];
int a[10000];
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int jj=1;jj<=t;jj++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		for(int i=1;i<=n;i++)
		{
			int maxx=l[i]-1;
			for(int j=1;j<=n;j++)
			{
				if((l[j]==l[i])&&(r[j]<r[i])) maxx=max(maxx,r[j]); 
			}
			a[i]=maxx+1;
		}
		for(int i=1;i<=n;i++) printf("%d %d %d\n",l[i],r[i],a[i]);
	}
	return 0;
}