#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1000005
#define ll long long
struct node{ll x,y,val;}a[N];
int sta[N],top,n;
ll f[N],ans;
inline bool cmp(const node &a,const node &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
#define K(i) (a[i].x)
#define B(i) (f[i])
#define Y(i,j) (-K(i)*a[j].y+B(i))

bool cmp1(int i,int j,int k)
{
	long double x=(long double)(K(i)-K(k))*(B(j)-B(i));
	long double y=(long double)(K(i)-K(j))*(B(k)-B(i));
	return x>=y;
}

int find(int x)
{
	int l=0,r=top;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(Y(sta[m],x)<Y(sta[m+1],x))l=m+1;
		else r=m;
	}return sta[l];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].val);
	sort(a+1,a+n+1,cmp);a[0].x=0,a[0].y=1<<30;
	for(int i=1;i<=n;i++)
	{
		int p=find(i);
		f[i]=f[p]+(a[i].x-a[p].x)*a[i].y-a[i].val;ans=max(ans,f[i]);
		while(top>=1&&cmp1(i,sta[top-1],sta[top]))top--;
		sta[++top]=i;
	}
	printf("%lld\n",ans);
}