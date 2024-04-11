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
typedef pair<ll,ll>LL;
vector<ll>z,q;
ll w,p=10,l=60;
ll mul(ll x,ll y)
{
	ll z=0;
	for(;y;y>>=1,x=x*2%p)
		if(y&1)
			z=(z+x)%p;
	return z;
}
LL F(ll x)
{
	if(x==0)
		return LL(0,1);
	if(x&1)
	{
		LL u=F(x-1);
		return LL(u.Y,(u.X+u.Y)%p);
	}
	else
	{
		LL u=F(x/2);
		return LL(mul(u.X,2*u.Y+p-u.X),(mul(u.X,u.X)+mul(u.Y,u.Y))%p);
	}
}
int main()
{
	cin>>w;
	for(int i=0;i<l;i++)
		if(F(i).X==w%p)
			z.push_back(i);
	for(int i=0;i<12;i++)
	{
		p*=10;
		q.clear();
		for(ll j:z)
			for(int k=0;k<10;k++)
				if(F(j+k*l).X==w%p)
					q.push_back(j+k*l);
		z.swap(q);
		l*=10;
	}
	if(!z.size())
		puts("-1");
	else
		cout<<*min_element(z.begin(),z.end());
}