//CF 779C
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
char t[200005],p[200005];
int a[200005],lt,lp;
int f[200005],pos;
bool ok(int x)
{
	if(pos<x)
	{
		for(pos=pos+1;pos<=x;pos=pos+1)
			f[a[pos]]=0;
	}
	if(pos>x)
	{
		for(;pos>x;pos=pos-1)
			f[a[pos]]=1;
	}
	pos=x;
	int i,j;
	/*cout<<pos<<endl;
	for(i=0;i<lt;i=i+1)
		cout<<f[i];
	cout<<endl;*/
	j=0;
	for(i=0;i<lt&&j<lp;i=i+1){
		if(f[i]&&t[i]==p[j])
			j=j+1;
	}
	if(j==lp)
		return true;
	return false;
}
int main()
{
	int i,l,r,m;
	scanf("%s%s",&t[0],&p[0]);
	lt=strlen(t);
	lp=strlen(p);
	for(i=1;i<=lt;i=i+1){
		cin>>a[i];
		a[i]=a[i]-1;
		f[i-1]=1;
	}
	pos=0;
	l=0;
	r=lt-lp;
	while(l<r){
		m=(l+r+1)/2;
		//cout<<l<<r<<m<<endl;
		if(ok(m))
			l=m;
		else
			r=m-1;
	}
	cout<<l<<endl;
	return 0;
}