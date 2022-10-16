#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
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
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<long long> a(n),b(n);
			for(int i=0;i<n;i++) cin>>a[i]>>b[i];
			long long ans=0,m=1e12+1;
			for(int i=0;i<n;i++)
			{
				long long v=max(a[i]-b[(n+i-1)%n],(long long)0);
				m=min(m,a[i]-v);
				ans+=v;	
			}	
			cout<<ans+m<<"\n";
		}
}