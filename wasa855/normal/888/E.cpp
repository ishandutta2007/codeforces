#include<bits/stdc++.h>
using namespace std;
int a[40];
int x[300005];
int sx,sy;
int y[300005];
int n,m;
int mid;
void dfs1(int now,int sum)
{
	if(now>mid)
	{
		x[++sx]=sum;
		return ;
	}
	dfs1(now+1,sum);
	dfs1(now+1,(sum+a[now])%m);
}
void dfs2(int now,int sum)
{
	if(now>n)
	{
		y[++sy]=sum;
		return ;
	}
	dfs2(now+1,sum);
	dfs2(now+1,(sum+a[now])%m);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==1)
	{
		cout<<a[1]%m<<endl;
		return 0;
	}
	mid=n/2;
	dfs1(1,0);
	dfs2(mid+1,0);
	sort(x+1,x+sx+1);
	sort(y+1,y+sy+1);
	int ans=0;
	int l=1,r=sy;
	while(l<=sx&&r>=1)
	{
		while(x[l]+y[r]>=m)
		{
			r--;
		}
		if((x[l]+y[r])%m>ans)
		{
			ans=(x[l]+y[r])%m;
		}
		l++;
	}
	cout<<ans<<endl;
	return 0;
}