#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
typedef pair<int,int> pii;

const int maxn = 2005;
ll a[maxn], b[maxn];
ll mx_len[maxn*maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ii cin>>a[i];
    ij cin>>b[i];
    ll x;
    cin>>x;
    for(int i=1;i<=n;++i) {
        ll s=0, len=0;
        for(int j=i;j<=n;++j) {
            s+=a[j];++len;
            mx_len[s]=max(mx_len[s], len);
        }
    }
    for(int i=1;i<=maxn*n;++i) mx_len[i]=max(mx_len[i-1],mx_len[i]);
    ll ans=0;
    for(int i=1;i<=m;++i) {
        ll s=0,len=0;
        for(int j=i;j<=m;++j) {
            s+=b[j];len++;
            ans=max(ans,mx_len[min(x/s,(ll)maxn*n)]*len);
        }
    }
    cout<<ans<<endl;
}