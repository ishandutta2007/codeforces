//template start//
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define vinput(a,n,v) for(int i=a;i<n;i++) cin>>v[i];
typedef double dd;
typedef long long ll;
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
// checks if a number is a perfect square in almost O(1) time
long long sqroot(long long n){
    long double N = n;
    N = sqrtl(N);
    long long sq = N-2;
    sq = max(sq,0LL);
    while(sq*sq<n){
        sq++;
    } 
    if((sq*sq)==n)
        return sq;
    return -1;
}
//exponent in log(m) time
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
int main()
{
    fast;
    TT
    {
        ll n,m;
        cin>>n>>m;
        set<tuple<ll,ll,ll>> s;
        for(int i=0;i<n;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            s.insert({a,b,c});
        }
        ll mn=m,mx=m,time=0;
        //cout<<mx<<" "<<mn<<"\n";
        bool lol=true;
        for(auto it=s.begin();it!=s.end();it++)
        {
            ll a,b,c;
            a=get<0>(*it);
            b=get<1>(*it);
            c=get<2>(*it);
            mn+=time-a;
            mx+=a-time;
            //cout<<a<<" "<<b<<" "<<c<<" "<<time<<"\n";
            //cout<<mn<<" "<<mx<<"\n";
            if(mn<=c&&mx>=b)
            {
                mn=max(mn,b);
                mx=min(mx,c);
                time=a;
            }
            else
            {
                cout<<"NO"<<"\n";
                lol=false;
                break;
            }
        }
        if(lol) cout<<"YES"<<"\n";
    }
}