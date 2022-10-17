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


int main() {
    ll c,b;
    cin>>c>>b;
    vector<ll> v;
    ll mn=1e18;
    for(ll i=1;i*i<=c;++i) if(c%i==0) v.push_back(c/i);
    for(ll i=1;i*i<=b;++i) if(b%i==0) v.push_back(b/i);
    sort(all(v));
    ll a=b+c;
    ll ans=0;
    for(ll i=1;i*i<=a;++i) {
        if(a%i==0) {
            int pos=upper_bound(all(v),a/i)-v.begin()-1;
            if(pos >= 0) {
                assert(v[pos] <= a/i);
                if(c % v[pos] == 0 && c / v[pos] <= i) ans=i;
                if(b % v[pos] == 0 && b / v[pos] <= i) ans=i;
            }
        }
    }
    cout<<(ans+a/ans)*2<<endl;
}