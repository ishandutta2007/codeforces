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
		vector<long long> v1,v2;
		long long l;
		for(int i=0;i<n;i++)
		{
			long long x;
			cin>>x;
			v1.push_back(x);
		}
		sort(v1.begin(),v1.end());
		for(int i=n/2;i<n;i++)
		{
			v2.push_back(v1[i]);
			if(i!=n-i-1)
			v2.push_back(v1[n-i-1]);
		}
		for(int i=0;i<n;i++) cout<<v2[i]<<" ";
			cout<<"\n";

	}	
}