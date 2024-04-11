#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<set>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
int n,m,F[100020];
ll cur,tim,z[100020];
set<ii>u1,u2,d1,d2;
struct N
{
	int s,f,r;
	ll t;
	void scan(int i)
	{
		r=i;
		scanf("%I64d %d %d",&t,&s,&f);
	}
}a[100020];
bool operator<(const N&a,const N&b)
{
	return a.t<b.t;
}
void push(int x,int y)
{
	if(x==cur)
	{
		z[y]=tim;
	}
	else if(x>cur)
		u1.insert(ii(x,y));
	else if(x<cur)
		d1.insert(ii(x,y));
}
ll getu(const set<ii>&s)
{
	if(s.size()==0)
		return 0x3f3f3f3f3f3f3fLL;
	return s.begin()->X;
}
ll getd(const set<ii>&s)
{
	if(s.size()==0)
		return 0;
	return s.rbegin()->X;
}
void move(ll dt)
{
	while(dt)
	{
		if(u1.size()+u2.size()==0&&d1.size()+d2.size()==0)
			break;
		if(u1.size()+u2.size()>=d1.size()+d2.size())
		{
			ll pos=min(getu(u1),getu(u2));
			pos=min(pos,cur+dt);
			tim+=pos-cur;
			dt-=pos-cur;
			cur=pos;
			while(u1.size()&&u1.begin()->X==pos)
			{
				z[u1.begin()->Y]=tim;
				u1.erase(u1.begin());
			}
			while(u2.size()&&u2.begin()->X==pos)
			{
				push(F[u2.begin()->Y],u2.begin()->Y);
				u2.erase(u2.begin());
			}
		}
		else
		{
			ll pos=max(getd(d1),getd(d2));
			pos=max(pos,cur-dt);
			tim+=cur-pos;
			dt-=cur-pos;
			cur=pos;
			while(d1.size()&&d1.rbegin()->X==pos)
			{
				z[d1.rbegin()->Y]=tim;
				d1.erase(--d1.end());
			}
			while(d2.size()&&d2.rbegin()->X==pos)
			{
				push(F[d2.rbegin()->Y],d2.rbegin()->Y);
				d2.erase(--d2.end());
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		a[i].scan(i);
		F[i]=a[i].f;
	}
	sort(a,a+n);
	cur=1;
	a[n].t=6000000020LL;
	for(int i=0;i<n;i++)
	{
		tim=a[i].t;
		if(cur==a[i].s)
			push(a[i].f,a[i].r);
		else if(cur<a[i].s)
			u2.insert(ii(a[i].s,a[i].r));
		else if(cur>a[i].s)
			d2.insert(ii(a[i].s,a[i].r));
		move(a[i+1].t-a[i].t);
	}
	for(int i=0;i<n;i++)
		printf("%I64d\n",z[i]);
}