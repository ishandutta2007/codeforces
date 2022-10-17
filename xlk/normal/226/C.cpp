#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll m,l,r,k;
pair<ll,ll>F(ll x)
{
    if(x==0)
    {
        return make_pair(0LL,1LL);
	}
    else if(x&1)
    {
		pair<ll,ll>u=F(x-1);
        return make_pair(u.Y,(u.X+u.Y)%m);
	}
    else
    {
		pair<ll,ll>u=F(x/2);
        return make_pair(u.X*(2*u.Y-u.X)%m,(u.X*u.X+u.Y*u.Y)%m);
	}
}
ll z;
int main()
{
	cin>>m>>l>>r>>k;
	if(k==1)
	{
		cout<<(F(r).X+m)%m;
		return 0;
	}
	l--;
	ll i=1;
	for(;i<=r;)
	{
		ll u;
		if(l>=i)
			u=min(l/(l/i),(r/(r/i)));
		else
			u=(r/(r/i));
		if(r/u-l/u>=k)
			z=max(z,u);
		i=u+1;
		if(r/i-l/i>=k)
			z=max(z,i);
	}
	cout<<(F(z).X+m)%m;
	return 0;
}