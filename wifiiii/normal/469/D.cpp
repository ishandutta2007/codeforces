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
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;

int c[100005],par[100005],ans[100005];
vector<int> vec[100005];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;++i) cin>>c[i],mp[c[i]]=i;
    ii par[i]=i;
    int fail = 0;
    for(int i=1;i<=n;++i) {
        int ok = 0;
        if(mp[a-c[i]]) par[find(i)] = find(mp[a-c[i]]), ok = 1;
        if(mp[b-c[i]]) par[find(i)] = find(mp[b-c[i]]), ok = 1;
        if(!ok) {
            fail = 1;
            break;
        }
    }
    if(fail) return cout<<"NO"<<endl,0;
    for(int i=1;i<=n;++i) vec[find(i)].pb(i);
    for(int i=1;i<=n;++i) {
        if(vec[i].size()) {
            unordered_map<int,int> vis;
            for(int x : vec[i]) vis[c[x]] = 1;
            int ok = 1;
            for(int x : vec[i]) {
                if(!vis[a-c[x]]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                for(int x : vec[i]) ans[x] = 0;
                continue;
            }
            ok = 1;
            for(int x : vec[i]) {
                if(!vis[b-c[x]]) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                for(int x : vec[i]) ans[x] = 1;
                continue;
            }
            return cout << "NO" << endl, 0;
        }
    }
    cout << "YES" << endl;
    ii cout << ans[i] << " "; cout << endl;
}