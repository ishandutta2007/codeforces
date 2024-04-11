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
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
typedef long double ld; 
typedef double dd;
typedef long long ll;
const int MOD = 998244353; // = (119<<23)+1
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
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
    ll n;
    cin>>n;
    vl v,prefix((n+1)/2);
    ll firsthalf=0;
    for(int i=0;i<(n+1)/2;i++)
    {
        int a;
        cin>>a;
        v.pb(a);
        firsthalf+=a;
    }
    prefix[0]=v[0];
    for(int i=1;i<(n+1)/2;i++)
    {
        prefix[i]=prefix[i-1]+v[i];
    }
    int x;
    cin>>x;
    ll totalsum=firsthalf + (n/2)*x;
    if(totalsum>0) cout<<n<<"\n";
    else
    {
        if(x>=0) cout<<-1<<'\n';
        else if(firsthalf<=0) cout<<-1<<"\n";
        else
        {
            vl length((n+1)/2);
            x=-x;
            for(int i=0;i<(n+1)/2;i++)
            {
                ll sum=firsthalf-(i==0?0:prefix[i-1]);
                //cout<<sum<<'\n';
                length[i]=(sum/x)+((n+1)/2) - i -(sum%x?0:1);
            }
            ll mn=1e9;
            bool ans=false;
            ll answer=-1;
            //cout<<length[0];
            //cout<<firsthalf<<"\n";
            //printvector(length);
            for(int i=0;i<length.size();i++)
            {
                mn=min(mn,length[i]);
                if(n-i<=mn)
                {
                    answer=n-i;
                    ans=true;
                }
                if(ans) break;

            }
            cout<<answer<<'\n';
        }
    }
}