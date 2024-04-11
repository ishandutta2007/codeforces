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

const int maxn = 200005;
const int mod = 998244353;
int a[maxn], rid[maxn], b[maxn];
int vis[maxn];
ll pw[maxn];
int main() {
    pw[0] = 1;
    for(int i=1;i<maxn;++i) pw[i]=pw[i-1]*2%mod;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        ii cin>>a[i],rid[a[i]]=i;
        for(int i=1;i<=k;++i) cin>>b[i],b[i]=rid[b[i]];
        ii vis[i] = 0;
        vis[0] = vis[n+1] = 1;
        for(int i=1;i<=k;++i) vis[b[i]] = 1;
        int ok = 1;
        for(int i=1;i<=k;++i) {
            if(vis[b[i]+1] && vis[b[i]-1]) {
                ok = 0;
                break;
            }
            vis[b[i]] = 0;
        }

        if(!ok) {cout << 0 << endl; continue;}
        sort(b+1, b+1+k);
        int cur=0;
        for(int i=1;i<=k;++i) {
            if(b[i]-b[i-1]!=1) cur++;
        }
        if(b[k]==n) cur--;
        cout<<pw[cur]<<endl;
    }
}