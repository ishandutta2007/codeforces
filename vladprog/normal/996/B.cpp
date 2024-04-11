/* dsingh_24 */
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll ,ll>
#define vll          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define N  100005

int main()
{
	ios
	ll i, j,x,mn=hell,n,b=0;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mn=min(a[i],mn);
	}
    if(mn>n) 
    {
        b=(mn-1)/n;
        for(i=0;i<=n;i++)
        	a[i]-=n*b;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]-i+1<=0) 
        {
            cout<<i;
            return 0;
        }
    }
    for(i=1;i<=n;i++)
    {
        a[i]-=n;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]-i+1<=0) 
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"HERE\n";
    for(i=1;i<=n;i++)
    {
        a[i]-=n;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]-i+1<=0) 
        {
            cout<<i;
            return 0;
        }
    }
    for(i=1;i<=n;i++)
    {
        a[i]-=n;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]-i+1<=0) 
        {
            cout<<i;
            return 0;
        }
    }
	return 0;
}