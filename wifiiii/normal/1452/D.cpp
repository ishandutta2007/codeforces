#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int mod=998244353;
ll fib(ll n) {
    function<ll(ll,ll,ll,ll,ll)> f = [&](ll a,ll b,ll p,ll q,ll n) -> ll {
        if(!n) return b;
        if(n&1) return f((b*q+a*q+a*p)%mod,(b*p+a*q)%mod,p,q,n-1);
        return f(a,b,(p*p+q*q)%mod,(q*q+2*q*p)%mod,n/2);
    };
    return f(1,0,0,1,n);
}
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    int n;
    while(cin>>n)cout<<fib(n)*fpow((mod+1)/2,n)%mod<<endl;
}