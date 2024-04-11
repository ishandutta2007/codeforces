#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}

int main()
{
	fast;
	long long t;
	cin >> t;
	while(t--)
	{
		long long x,y,a,b,ans;
		cin >>x>>y>>a>>b;
		if(2*a<=b)
		{
			ans=(x+y)*a;
		}
		else
		{
			ans=b*min(x, y)+ a*(max(x,y)-min(x,y));
		}
		cout<<ans<<"\n";
	}
}