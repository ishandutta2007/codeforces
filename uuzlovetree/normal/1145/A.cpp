#include<bits/stdc++.h>
using namespace std;
int n;
int a[20];
int ans;
bool sorted(int l,int r)
{
	for(int i=l;i<r;++i)if(a[i]>a[i+1])return 0;
	return 1;
}
void solve(int l,int r)
{
	int mid=(l+r)>>1;
	if(sorted(l,r))
	{
		ans=max(ans,r-l+1);
		return;
	}
	solve(l,mid);solve(mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	solve(1,n);
	printf("%d\n",ans);
	return 0;
}