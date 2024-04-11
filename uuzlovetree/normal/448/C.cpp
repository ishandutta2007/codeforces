#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
int n;
int a[maxn];
int solve(int l,int r,int k)
{
	if(l>r)return 0;
	if(l==r)return 1;
	vector<int> v;
	v.clear();
	int minv=(int)1e9;
	for(int p=l;p<=r;++p)minv=min(minv,a[p]);
	v.push_back(l-1);
	for(int p=l;p<=r;++p)if(a[p]==minv)v.push_back(p);
	v.push_back(r+1);
	int ans=minv-k;
	for(int i=1;i<v.size();++i)
	{
		int x=v[i];
		ans+=solve(v[i-1]+1,v[i]-1,minv);
	}
	return min(ans,r-l+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=solve(1,n,0);
	printf("%d\n",ans);
	return 0;
}