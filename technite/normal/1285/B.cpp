#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
void printvector(vector<long long> v)
{
    for (auto x : v)
        cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> v(n),dp(n);
        for(int i=0;i<n;i++) cin>>v[i];
        long long totalsum=v[0],rangesum=v[0],sum=0;
        bool ok=false;
        dp[0]=v[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1]+v[i],v[i]);
            if(v[i]>dp[i-1]+v[i]) ok=true;
            rangesum=max(dp[i],rangesum);
            if(totalsum==0)ok=true;
            totalsum+=v[i];        
        } 
        if(rangesum!=dp[n-1])ok=true;
        if(ok!=true&&rangesum==dp[n-1])
        {
            ok=false;
            for(int i=0;i<n-2;i++)
            {
                if(dp[i]==dp[n-1])
                {
                    ok=true;
                    break;
                }
            }
        }
        //cout<<totalsum<<' '<<rangesum<<endl;
        if(!ok) rangesum-=min(v[0],v[n-1]);
        //cout<<rangesum<<endl;
        if(totalsum>rangesum) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}