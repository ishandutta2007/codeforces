#include <bits/stdc++.h>
#define ll long long
#define INF 5*1e18
using namespace std;
ll gcd(ll a,ll b,ll& x,ll& y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}	
		ll ans=gcd(b,a%b,x,y);
		int temp=x;
		x=y;
		y=temp-a/b*y;
		return ans;
}
int main()
{
	ll a,b,c,d,x,y;
	cin>>a>>b>>c; 
	d=gcd(a,b,x,y);
	if(c%d!=0)
		cout<<-1<<endl;
	else
		cout<<-x*(c/d)<<" "<<-y*(c/d)<<endl;
	return 0;
}