#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define endl "\n";
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
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<long long> v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		long long mx=v[0],mxdiff=0;
		for(int i=1;i<n;i++)
		{
			if(v[i]<mx)
			{
				mxdiff=max(mxdiff,mx-v[i]);
			}
			if(v[i]>mx) mx=v[i];
		}	
		long long x=0;
		long long sum=0;
		while(sum<mxdiff)
		{
			sum+=1<<(x);
			x++;
		}
		if(mxdiff==0) cout<<0<<endl;
		if(mxdiff>0) cout<<x<<endl;
	}
}