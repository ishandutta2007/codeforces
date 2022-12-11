#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<ll> A,B;
ll s[1005];
vector<ll> X,Y,Z,W;
ll ask(ll t,ll i,ll j,ll k)
{
	ll x;
	cout<<t<<" "<<i<<" "<<j<<" "<<k<<endl;
	fflush(stdout);
	cin>>x;
	return x;
}
bool cmp1(int x,int y)
{
	return s[x]<s[y];
}
bool cmp2(int x,int y)
{
	return s[x]>s[y];
}
int main()
{
	cin>>n;
	for(int i=3;i<=n;++i)
	{
		ll x=ask(2,1,i,2);
		if(x>0)A.push_back(i);
		else B.push_back(i);
	}
	ll ida=0,sa=0,idb=0,sb=0;
	for(ll x:A)
	{
		ll y=ask(1,1,x,2);
		s[x]=y;
		if(y>sa)ida=x,sa=y;
	}
	for(ll x:B)
	{
		ll y=ask(1,1,x,2);
		s[x]=y;
		if(y>sb)idb=x,sb=y;
	}
	for(ll x:A)if(x!=ida)
	{
		ll y=ask(2,1,x,ida);
		if(y<0)Y.push_back(x);
		else X.push_back(x);
	}
	for(ll x:B)if(x!=idb)
	{
		ll y=ask(2,1,x,idb);
		if(y<0)W.push_back(x);
		else Z.push_back(x);
	}
	sort(X.begin(),X.end(),cmp1);
	sort(Y.begin(),Y.end(),cmp2);
	sort(Z.begin(),Z.end(),cmp1);
	sort(W.begin(),W.end(),cmp2);
	cout<<0<<" ";
	cout<<1<<" ";
	for(ll x:X)cout<<x<<" ";
	if(ida)cout<<ida<<" ";
	for(ll x:Y)cout<<x<<" ";
	cout<<2<<" ";
	for(ll x:Z)cout<<x<<" ";
	if(idb)cout<<idb<<" ";
	for(ll x:W)cout<<x<<" ";
}