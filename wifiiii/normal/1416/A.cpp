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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;


const int maxn = 300005;
int a[maxn];
vector<int> g[maxn];
int ans[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        ii cin >> a[i];
        ii g[i].clear();
        ii g[a[i]].push_back(i);
        ii ans[i] = 1e9;
        for(int i=1;i<=n;++i) {
            if(g[i].empty()) continue;
            int mn=0,lst=0;
            for(int v:g[i]) {
                mn=max(mn,v-lst);
                lst=v;
            }
            mn=max(mn,n+1-lst);
            ans[mn]=min(ans[mn],i);
        }
        for(int i=2;i<=n;++i) ans[i]=min(ans[i],ans[i-1]);
        ii cout<<(ans[i]>=1e9?-1:ans[i])<<" ";cout<<endl;
    }
}