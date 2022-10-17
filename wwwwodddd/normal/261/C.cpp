#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll n,t;
map<pair<ll,int>,ll>f;
ll F(ll n,int t)
{
	if(t<0)
		return 0;
	if(f.count(make_pair(n,t)))
		return f[make_pair(n,t)];
//	cout << n << " " <<t << endl;
	if(n==1)
		return t==0;
	int i;
	for(i=0;1LL<<i+1<n;i++)
		;
	return f[make_pair(n,t)]=F(1LL<<i,t)+F(n-(1LL<<i),t-1);
}
ll N;
ll C(ll n,int t)
{
	ll s=0;
	for(int i=1;1LL<<i<n;i++)
	{
		n-=1LL<<i;
		s+=F(1LL<<i,t);
	}
	return s+F(n,t);
}
int main()
{
	ll x,y;
	cin>>n>>t;
	N=n;
	if(t&t-1)
	{
		cout<<0;
		return 0;
	}
	int s;
	for(int i=0;i<60;i++)
	{
		if(1LL<<i==t)
			s=i;
	}
	ll z=C(n,s);
	cout<<z<<endl;
	return 0;
}