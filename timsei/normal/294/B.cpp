#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 101
int ans;
int n;
int k2[N];
int l1,l2;
int k1[N];
int l,r=0;
int ho,ku;
bool cmp(int x,int y)
{
	return x>y;
}
bool pd(int x)
{
	int res=0;
	for(int i=0;i<=x/2;i++)
	{
		if(i>l2) break;
		res=0;
		int j=x-2*i;
		if(j>l1) continue;
		if(j<0) break;
		for(int k=i+1;k<=l2;k++) res+=k2[k];
		for(int k=j+1;k<=l1;k++) res+=k1[k];
		if(res<=x) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ho,&ku);
		if(ho==1) k1[++l1]=ku;
		else k2[++l2]=ku;
		r+=ho;
	}
	l=1;
	sort(k1+1,k1+l1+1,cmp);
	sort(k2+1,k2+l2+1,cmp);
//	for(int i=1;i<=l2;i++) cout<<k2[i]<<" ";
//	cout<<r<<endl;
	ans=r;
	for(int i=l;i<=r;i++)
	{
		if(pd(i))
		{
			ans=min(ans,i);
		}
	}
	printf("%d",ans);
}