#include<bits/stdc++.h>
using namespace std;
const int N=350005;
const long long inf=1e12;
int n,a[N],l[N],r[N];
priority_queue<long long>x;
priority_queue<long long,vector<long long>,greater<long long>>y;
long long tx,ty,p;
long long chk(long long v)
{
	while(x.size())
		x.pop();
	while(y.size())
		y.pop();
	x.push(-inf),y.push(inf);
	tx=ty=p=0;
	for(int i=1;i<=n;i++)
		x.push(v),y.push(v);
	for(int i=1;i<=n;i++)
	{
		tx+=a[i]-r[i];
		ty+=a[i]-l[i];
		long long q;
		q=y.top()+ty;
		if(q<0)
		{
			p-=q;
			y.pop();
			x.push(q-tx);
			y.push(-ty);
		}
		else
			x.push(-tx);
		q=x.top()+tx;
		if(q>0)
		{
			p+=q;
			x.pop();
			y.push(q-ty);
			x.push(-tx);
		}
		else
			y.push(-ty);
	}
	if(v<x.top()+tx)
	{
		for(;x.size()&&x.top()+tx>v;x.pop())
			p+=(x.top()+tx)-v;
	}
	else
	{
		for(;y.size()&&y.top()+ty<v;y.pop())
			p+=v-(y.top()+ty);
	}
	return p;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&l[i],&r[i]);
	long long lb=-1ll*n*n,rb=1ll*n*n;
	while(rb-lb>1)
	{
		long long m=lb+rb>>1;
		if(chk(m)<chk(m+1))
			rb=m;
		else
			lb=m;
	}
	printf("%lld\n",chk(rb));
	return 0;
}