#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
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
    int n;
    cin>>n;
    vector<int> adj[n+1];
    vector<pair<int,int>> v;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        v.push_back({a,b});
    }
    int x=0;
    int index=0;
    for(int i=1;i<=n;i++)
    {
        int sz=adj[i].size();
        x=max(x,sz);
        if(sz>=3) index=i;
    }
    if(x>=3)
    {
        int t=3;
        int count1=3;
        int count2=0;
        for(int i=0;i<n-1;i++)
        {
            if(t>0&&(v[i].first==index||v[i].second==index))
            {
                cout<<count2++<<"\n";
                t--;
            }
            else cout<<count1++<<"\n";
        }
    }
    else
    {
         for(int i=0;i<n-1;i++)
        {
            cout<<i<<"\n";
        }
    }
}