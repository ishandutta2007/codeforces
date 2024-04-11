//CF 837E
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
LL a[111111];
LL gcd(LL x,LL y)
{
	if(x<y)
		swap(x,y);
	LL r;
	r=x%y;
	while(r){
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main()
{
	LL x,y,t,ans,maxs,maxp,s;
	int n,i;
	cin>>x>>y;
	n=0;
	for(i=1;(LL)i*i<=x;i=i+1){
		if(x%i==0){
			n++;
			a[n]=i;
			if((LL)i*i!=x){
				n++;
				a[n]=x/i;
			}
		}
	}
	t=gcd(x,y);
	ans=0;
	while(y&&t<x){
		maxs=0;
		maxp=x;
		for(i=1;i<=n;i=i+1){
			if(a[i]>t&&a[i]%t==0){
				s=(y/a[i])*a[i];
				if(s>maxs){
					maxs=s;
					maxp=a[i];
				}
			}
		}
		//cout<<maxs<<maxp<<endl;
		ans+=(y-maxs)/t;
		y=maxs;
		t=maxp;
	}
	if(y)
		ans+=y/x;
	cout<<ans<<endl;
	return 0;
}