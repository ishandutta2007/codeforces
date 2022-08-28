//CF 862D
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
int n,s0,s1,p0,p1;
int ask(int l,int r){
	int i;
	cout<<"? ";
	for(i=1;i<=n;i=i+1){
		if(l<=i&&i<=r)
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
	cin>>i;
	return i;
}
void f(int x,int l,int r)
{
	//cout<<x<<l<<r<<endl;
	if(l==r){
		if(x){
			if(!p1) p1=l;
		}
		else{
			if(!p0) p0=l;
		}
		return;
	}
	int md,t0,t1,t;
	md=(l+r)/2;
	t=md-l+1;
	t1=(t+s1-ask(l,md))/2;
	t0=t-t1;
	//cout<<t0<<t1<<endl;
	if(!t0){
		if(!p1) p1=l;
		f(0,md+1,r);
		return;
	}
	if(!t1){
		if(!p0) p0=l;
		f(1,md+1,r);
		return;
	}
	f(2,l,md);
}
int main()
{
	cin>>n;
	s1=ask(n,1);
	s0=n-s1;
	f(2,1,n);
	cout<<"! "<<p0<<' '<<p1<<endl;
	return 0;
}