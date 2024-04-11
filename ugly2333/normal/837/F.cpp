//CF 837F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int n,a[222222];
LL k;
bool ok(LL p)
{
	LL t,c,x,y;
	int i;
	double d,h;
	t=k;
	c=1;
	x=0;
	y=p;
	for(i=n;i>=1;i=i-1){
		if(a[i]){
			if(c==-1)
				return 1;
			d=(double)t/a[i];
			if((double)c>d)
				return 1;
			t-=a[i]*c;
		}
		x++;
		y++;
		d=(double)y/x;
		h=(double)t/c;
		if(d>h)
			c=-1;
		else
			c=(LL)(c*d+0.5);
		//cout<<c<<' '<<t<<endl;
	}
	return (t<=0);
}
int main()
{
	int i;
	LL l,r,md;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(a[i]>=k){
			cout<<0<<endl;
			return 0;
		}
	}
	l=0;
	r=k;
	while(l<r){
		md=(l+r)/2;
		if(ok(md))
			r=md;
		else
			l=md+1;
	}
	cout<<l+1<<endl;
	return 0;
}