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
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
        cin >> n;
        int a[n+1];
        vector<int> v[300];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            v[a[i]].push_back(i);
        }
        int ans=0;
        for(int i=1;i<=200;i++)
        {
           	ans=max(ans,(int)v[i].size());
            
	           int x=v[i].size()/2-1;
    	        for(int j=0;j<=x;j++)
    	        {
        	        for(int k=1;k<=200;k++)
        	        {
            	        if(k!=i) ans=max(ans,2*(j+1)+(lower_bound(v[k].begin(),v[k].end(),v[i][v[i].size()-1-j])-lower_bound(v[k].begin(),v[k].end(),v[i][j])));
                	}
            	}
            
        }
        cout<<ans<<"\n";
    }
}