#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,a[400005],num[400005],tot,v[400005],res;
int ans[400005];
vector<int>out[400005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])tot++;
		num[tot]++;
		v[tot]=a[i];
	}
	int maxa=0;
	for(int i=1;i*i<=n;i++)
	{
		int ans=0;
		for(int j=1;j<=tot;j++)
		  ans+=min(i,num[j]);
		ans/=i;
		if(ans>=i)
		{
			ans*=i;
			if(ans>res)
			{
				res=ans;
				maxa=i;
			}
		}
	}
	int now=0;
	for(int i=1;i<=tot;i++)
	{
		if(num[i]>=maxa)
		  for(int j=1;j<=min(maxa,num[i]);j++)
		    ans[++now]=v[i];
	}
	for(int i=1;i<=tot;i++)
	{
		if(num[i]<maxa)
		  for(int j=1;j<=min(maxa,num[i]);j++)
		    ans[++now]=v[i];
	}
	res/=maxa;
	printf("%d\n%d %d\n",res*maxa,res,maxa);
	for(int i=1;i<=res;i++)
	  for(int j=1;j<=maxa;j++)
	    out[i].push_back(ans[(i-1)*maxa+j]);
	int x=1,y=0;
	for(int i=1;i<=res*maxa;i++)
	{
		out[(x-1)%res+1][y]=ans[i];
		x++,y++;
		if(y==maxa)y=0,x-=maxa-1;
	}
	for(int i=1;i<=res;i++)
	{
		for(int j=0;j<maxa;j++)
		  printf("%d ",out[i][j]);
		printf("\n");
	}
	return 0;
}