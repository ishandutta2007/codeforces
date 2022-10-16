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
    TT
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        bool b=false;
        for(int i=0;i<n;i++) {cin>>v[i];if(v[i]==k) b=true;}
        bool a=false;
        if(n==1&&b) a=true;
        if(!a){
        for(int i=0;i<n-1;i++)
        {
            if(v[i]>=k&&v[i+1]>=k) a=true;
        }    
        }
        if(!a&&b)
        {
            for(int i=0;i<n-2;i++)
            {
                if(v[i]>=k&&v[i+2]>=k) a=true;
            }
        }
        if(a&&b) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }    
}