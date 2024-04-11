#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(it,st,en) for(ll it=(st);it<(ll)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef unsigned long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;
const ll mod = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,l,k;
    cin>>n>>l>>k;
    map<ll,ll> a,al;
    rep(i,0,n){
        ll x;
        cin>>x;
        a[x]++;
        if(i<l%n)al[x]++;
    }
    ll ans=0;
    ll K=min(k,l/n);
    vector<vector<ll> > dp(K+10,vector<ll>(a.size()+10,0));
    dp[0][0]=1;
    rep(i,1,K+1){
        ll j=0;
        ll sm=0;
        for(auto p:a){
            sm=(sm+dp[i-1][j])%mod;
            dp[i][j]=(sm*p.Y)%mod;
            ans+=(((l/n-i+1)%mod)*dp[i][j])%mod;
            ans%=mod;
            j++;
        }
    }
    K=min(k,(l+n-1)/n);
    rep(i,1,K+1){
        ll j=0;
        ll sm=0;
        for(auto p:a){
            sm=(sm+dp[i-1][j])%mod;
            if(al.count(p.first)){
                ans+=(sm*al[p.first])%mod;
                ans%=mod;
            }
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}