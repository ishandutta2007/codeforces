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
        long long a,b;
        cin>>a>>b;
        if(b==a) cout<<0<<endl;
        if(b>a&&(b-a)%2) cout<<1<<endl;
        else if(b>a&&(b-a)%2==0) cout<<2<<endl;
        else if(b<a)
        {
            if((b-a)%2) cout<<2<<endl;
            else cout<<1<<endl;
        }
    }
    
}