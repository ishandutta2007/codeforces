#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int p[max_n],pos[max_n],ans;
void solve(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1,mx=0;
	for(int i=mid,j=mid;i>=l;--i)
	{
		if(p[i]>mx)
			mx=p[i];
		else
		{
			while(j+1<=r&&p[j+1]<mx)
				++j;
			int x=pos[mx-p[i]];
			ans+=x>=mid+1&&x<=j;
		}
	}
	mx=0;
	for(int i=mid+1,j=mid+1;i<=r;++i)
	{
		if(p[i]>mx)
			mx=p[i];
		else
		{
			while(j-1>=l&&p[j-1]<mx)
				--j;
			int x=pos[mx-p[i]];
			ans+=x<=mid&&x>=j;
		}
	}
	solve(l,mid);
	solve(mid+1,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",p+i);
		pos[p[i]]=i;
	}
	solve(1,n);
	printf("%d\n",ans);
	return 0;
}