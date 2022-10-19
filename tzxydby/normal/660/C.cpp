#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int a[N],s[N];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i]; 
	}
	int l=0,ma=0,id=0;
	for(int r=1;r<=n;r++)
	{
		while(s[r]-s[l]+k<r-l)
			l++;
		if(r-l>ma)
		{
			id=r;
			ma=r-l;
		}
	}
	printf("%d\n",ma);
	for(int i=id;i>0;i--)
	{
		if(k&&a[i]==0)
		{
			k--;
			a[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}