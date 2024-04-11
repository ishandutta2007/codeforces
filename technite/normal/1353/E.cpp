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
	TT
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ones = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            ones++;
        }
        int ans = ones;
        for(int i =0;i<k;i++)
        {
            int x=0;
            for(ll j=i;j<n;j+=k)
            {
                if(s[j]=='1')
                x++;
                else x--;
                x=max(x,0);
                ans=min(ans,ones-x);
            }
            
        }
        cout<<ans<<"\n";
    }
}