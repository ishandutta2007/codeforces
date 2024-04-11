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
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
            int h;
            cin>>h;
            h--;
            b[i]=h;
        }
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(a[b[j]+1]<a[b[j]]) swap(a[b[j]+1],a[b[j]]);
            }
        }
        if(is_sorted(a.begin(),a.end())) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";

    }
    
}