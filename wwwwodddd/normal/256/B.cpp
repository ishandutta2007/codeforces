#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll n,x,y;
ll c;
ll cal(ll t)
{
	ll s=t*t+(t+1)*(t+1);
	if(x-t<=0)
		s-=(t-x+1)*(t-x+1);
	if(y-t<=0)
		s-=(t-y+1)*(t-y+1);
	if(x+t>n)
		s-=(x+t-n)*(x+t-n);
	if(y+t>n)
		s-=(y+t-n)*(y+t-n);
	if(x+y-t<=0)
		s+=(t-x-y+1)*(t-x-y+2)/2;
	if(x+n-y+1-t<=0)
		s+=(t-x-(n-y+1)+1)*(t-x-(n-y+1)+2)/2;
	if(n-x+1+y-t<=0)
		s+=(t-y-(n-x+1)+1)*(t-y-(n-x+1)+2)/2;
	if(n-x+1+n-y+1-t<=0)
		s+=(t-(n-y+1)-(n-x+1)+1)*(t-(n-y+1)-(n-x+1)+2)/2;
	return s;
}
int main()
{
	cin>>n>>x>>y>>c;
	ll L=0,R=3LL*n;
	while(L<R)
	{
		int m=(L+R)>>1;
		ll u=cal(m);
		if(u<c)
			L=m+1;
		else
			R=m;
	}
	cout << L << endl;
}