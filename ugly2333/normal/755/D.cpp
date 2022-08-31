//CF 755D
#include<iostream>
#include<cstdio>
using namespace std;
long long t[1000005];
int n;
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int v)
{
	for(;x<=n;x=x+lowbit(x))
		t[x]=(long long)v+t[x];
	return;
}
long long query(int l,int r)
{
	long long s;
	s=0;
	if(l>r)
		return 0;
	for(;r>0;r=r-lowbit(r))
		s=s+t[r];
	for(l=l-1;l>0;l=l-lowbit(l))
		s=s-t[l];
	return s;
}
int main()
{
	int k,i,x,p;
	long long ans;
	cin>>n>>k;
	k=min(k,n-k);
	ans=1;
	x=1;
	p=1+k;
	for(i=1;i<=n;i=i+1)
	{
		if(x>p)
			ans=ans+query(x+1,n)+query(1,p-1);
		else
			ans=ans+query(x+1,p-1);
		ans=(long long)1+ans;
		printf("%I64d ",ans);
		add(x,1);
		add(p,1);
		x=p;
		p=p+k;
		if(p>n)
			p=p-n;
	}
	return 0;
}