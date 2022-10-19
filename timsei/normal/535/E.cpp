#include<cstdio>
#include<iostream>
#include"algorithm"
#include<cstring>
#include<map>
using namespace std;
#define N 500001
int n;
struct node
{
	int s,r,no;
}xx[N],dance[N],fire[N];
bool cmp(node x,node y)
{
	return x.s>y.s||(x.s==y.s&&x.r>y.r);
}
int S[N];
int ans[N];
int mal=0;
int k;
int q;
bool yes[N];
double eps=1e-6;
int h,t;
map<int,int>X;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>xx[i].s>>xx[i].r;
	for(int i=1;i<=n;i++) xx[i].no=i;
	sort(xx+1,xx+n+1,cmp);
//	dance[++k]=xx[1];
	for(int i=1;i<=n;i++)
	{
		if(mal>xx[i].r) continue;
		if(mal==xx[i].r&&q==xx[i].s)
		{
			dance[++k]=xx[i];continue;
		}
		if(q==xx[i].s)continue;
		if(mal==xx[i].r)continue;
		{
			dance[++k]=xx[i];
			mal=xx[i].r;
			q=xx[i].s;
		}
	}
	h=1;fire[++t]=dance[1];
	for(int i=2;i<=k;i++)
	{
		if(h<=t&&dance[i].r<=fire[t].r) continue; 
		while(h<t)
		{
			long long s1=fire[t-1].s,s2=fire[t].s,r1=fire[t-1].r,r2=fire[t].r;
			long long s3=dance[i].s,r3=dance[i].r;
			long long k1=(s3-s2)*(r1-r2)*r3*s1;
			long long k2=(s1-s2)*(r3-r2)*r1*s3;
			if(k1<k2)t--;else break;	
		}
		fire[++t]=dance[i];
	}
	int xxx=0;
	for(int i=1;i<=t;i++)
	{
		X[fire[i].s]=fire[i].r;
	}
	for(int i=1;i<=n;i++)
	{
		if(X[xx[i].s]==xx[i].r)
		ans[++xxx]=xx[i].no;
	}
	sort(ans+1,ans+xxx+1);
	for(int i=1;i<=xxx;i++) cout<<ans[i]<<" ";
}