#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
namespace RP
{
int n;
typedef long long ll;
int qzmax[100003],hzmax[100003],qzmin[100003],hzmin[100003];
struct pt {int x,y;} cs[233333];
int Abs(int x) {return x>=0?x:-x;}
bool operator < (pt a,pt b) {return a.x<b.x;}
ll sqr(ll x) {return (ll)x*x;}
bool ok(ll x)
{
	for(int p=0;p<=1;p++)
	{
	for(int i=1;i<=n;i++) cs[i].x=-cs[i].x;
	for(int i=1;i<=n;i++)
	{
		if(i<n+1-i) swap(cs[i],cs[n+1-i]);
		else break;
	}
	memset(qzmax,-127/3,sizeof(qzmax));
	memset(hzmax,-127/3,sizeof(hzmax));
	memset(qzmin,127/3,sizeof(qzmin));
	memset(hzmin,127/3,sizeof(hzmin));
	for(int i=1;i<=n;i++) qzmax[i]=max(qzmax[i-1],cs[i].y);
	for(int i=n;i>=1;i--) hzmax[i]=max(hzmax[i+1],cs[i].y);
	for(int i=1;i<=n;i++) qzmin[i]=min(qzmin[i-1],cs[i].y);
	for(int i=n;i>=1;i--) hzmin[i]=min(hzmin[i+1],cs[i].y);
	int rr,lr;
	rr=n,lr=1;
	for(int i=1;i<=n;i++)
	{
		if(cs[i].x>0) break;
		while(rr>i&&Abs(cs[i].x)<Abs(cs[rr].x)) --rr;
		lr=max(lr,i);
		while(lr<=n&&cs[lr+1].x>=cs[i].x&&sqr(cs[lr+1].x-cs[i].x)<=x) ++lr;
		int r=min(lr,rr);
		if(r<i) r=i; if(r>n) r=n;
		if(i==1&&r==n) return 1;
		int ymax=max(qzmax[i-1],hzmax[r+1]),ymin=min(qzmin[i-1],hzmin[r+1]);
		if(sqr(ymax-ymin)<=x&&sqr(cs[i].x)+sqr(ymax)<=x&&sqr(cs[i].x)+sqr(ymin)<=x)
		return 1;
	}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&cs[i].x,&cs[i].y);
	sort(cs+1,cs+1+n);
	ll cans=100000000000000000LL;
	//only x
	{
		ll minn=100000001,maxn=-100000001;
		for(int i=1;i<=n;i++)
		{
			int c=cs[i].x;
			if(c<minn) minn=c;
			if(c>maxn) maxn=c;
		}
		cans=min(cans,(maxn-minn)*(maxn-minn));
	}
	//only y
	{
		ll minn=100000001,maxn=-100000001;
		for(int i=1;i<=n;i++)
		{
			int c=cs[i].y;
			if(c<minn) minn=c;
			if(c>maxn) maxn=c;
		}
		cans=min(cans,(maxn-minn)*(maxn-minn));
	}
	ll l=0,r=100000000000000000LL;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(ok(mid)) r=mid;
		else l=mid+1;
	}
	cout<<min(l,cans)<<"\n";
}
}
int main()
{
	RP::main();
}