using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 200001
int n,color[100001];
int ans[N];
int confuse[100001];
bool num[100001];
int cal(int x)
{
	if(confuse[x]) return confuse[x];
	for(int l=1;l<=n;)
	{
		int cnt=0;
		int f=l;
		while(cnt<x&&f<=n)
		{
			if(!num[color[f]])cnt++;
			num[color[f++]]=1;
		}
		while(num[color[f]]&&f<=n)f++;
		if(!num[color[f]])f--;
		for(int k=l;k<=f;k++) num[color[k]]=0;
		confuse[x]++;l=f+1;
	}
	return confuse[x];
}
void doit(int l,int r)
{
	if(l>r) return;
	int rr=r,ll=l+1;
	int an=l;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1;
		if(cal(mid)==cal(l))
		{
			ll=mid+1;an=mid;
		}
		else
		rr=mid-1;
	}
	for(int i=l;i<=an;i++) 
	{
		ans[i]=cal(l);
	}
	doit(an+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&color[i]);
	doit(1,n);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}