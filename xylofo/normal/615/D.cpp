#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;
const ll MOD = 1000000007;

ll powmod(ll x, ll n){
    ll ans=1;
    while(n){
        if(n&1)ans=(ans*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n;
    map<ll,ll> m;
    rep(i,0,n)cin>>x,m[x]++;
    bool sq=true;
    for(auto p:m)if(p.Y%2)sq=false;
    if(sq){
        x=1;
        for(auto p:m)
            rep(i,0,p.Y/2)x=(x*p.X)%MOD;
        for(auto p:m)
            x=powmod(x,p.Y+1);
        cout<<x<<endl;
    }
    else{
        x=1;
        for(auto p:m)
            rep(i,0,p.Y)x=(x*p.X)%MOD;
        for(auto p:m)
            if(!sq && (p.Y&1))sq=1,x=powmod(x,(p.Y+1)/2);
            else x=powmod(x,p.Y+1);
        cout<<x<<endl;
    }

    return 0;
}