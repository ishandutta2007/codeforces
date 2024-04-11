#include<bits/stdc++.h>
using namespace std;
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
void printarray(int a[], int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void printvector(vector<int> v)
{
    for (auto x : v)
        cout<<x<<" ";
    cout<<"\n";
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
        long long a[n+10]={},dp[n+10]={};
        for(int i=0;i<n;i++) cin>>a[i];
           for(int i=n;i>=1;i--)
           {
                ll to=i*2,k=3;
                ll cnt=1;
                while(1)
                {
                    if(to>=n+1) break;
                    if(a[i-1]<a[to-1]) cnt=max(cnt,dp[to]+1);
                    to=i*k;
                    k++;
                }
                dp[i]=cnt;
           } 
           ll ans=1;
           for(int i=0;i<n+1;i++) ans=max(ans,dp[i]);
           cout<<ans<<"\n"; 

    }
}