#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
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
template<typename T>
void printvector(vector<T>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<"\n";
}
template<typename T>
void printarray(T a[])
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<"\n";
}
 
void printpairs(vector<pair<int,int>>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].F<<','<<v[i].S<<'|';
    }
    cout<<endl;
}
 
void print2d(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        printvector(v[i]);
    }
}
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)

 
int main()
{
    fast;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int sz=max(b+c+1,d+2);
    vector<ll> v(sz,0);
    for(int i=max(c+1,a+b);i<=b+c;i++)
    {
            int x=max(i-c,a);
            int y=min(c,i-a);
            v[i]=min(b-x+1,y-b+1);
    }
   // printvector(v);
    for(int i=sz-2;i>c;i--)
    {
        v[i]+=v[i+1];
    }
    // printvector(v);
    ll ans=0;
    for(int i=c;i<=d;i++)
    {
        ans+=v[i+1];
        //cout<<ans<<" ";
    }
    cout<<ans;
}