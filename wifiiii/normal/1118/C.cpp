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

// x x x x x
// x x x x x
const int maxn = 100005;
int par[maxn],sz[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x==y) return;
    par[x]=y;
    sz[y]+=sz[x];
}
vector<int> g[maxn];
int mp[1005];
int ans[4005];
int main() {
    int n;cin>>n;
    for(int i=1;i<=n*n;++i) par[i]=i,sz[i]=1;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            int x=n+1-i,y=j;
            merge((i-1)*n+j, (x-1)*n+y);
            x=i,y=n+1-j;
            merge((i-1)*n+j, (x-1)*n+y);
        }
    }
    for(int i=1;i<=n*n;++i) {
        int x;
        cin>>x;
        mp[x]++;
    }
    for(int i=1;i<=n*n;++i) g[find(i)].push_back(i);
    int okk = 1;
    for(int i=1;i<=n*n;++i) {
        if(g[i].size() != 4) continue;
        int ok = 0;
        for(int j=1;j<=1000;++j) {
            if(mp[j] == g[i].size()) {
                ok = 1;
                for(int k : g[i]) {
                    ans[k] = j;
                }
                mp[j] = 0;
                break;
            }
        }
        if(!ok) {
            for(int j=1;j<=1000;++j) {
                if(mp[j] > g[i].size()) {
                    ok = 1;
                    for(int k : g[i]) {
                        ans[k] = j;
                    }
                    mp[j] -= g[i].size();
                    break;
                }
            }
        }
        if(!ok) {
            okk = 0;
            break;
        }
    }
    if(!okk) {cout << "NO\n";return 0;}

    for(int i=1;i<=n*n;++i) {
        if(g[i].size() != 2) continue;
        int ok = 0;
        for(int j=1;j<=1000;++j) {
            if(mp[j] == g[i].size()) {
                ok = 1;
                for(int k : g[i]) {
                    ans[k] = j;
                }
                mp[j] = 0;
                break;
            }
        }
        if(!ok) {
            for(int j=1;j<=1000;++j) {
                if(mp[j] > g[i].size()) {
                    ok = 1;
                    for(int k : g[i]) {
                        ans[k] = j;
                    }
                    mp[j] -= g[i].size();
                    break;
                }
            }
        }
        if(!ok) {
            okk = 0;
            break;
        }
    }
    if(!okk) {cout << "NO\n";return 0;}

    for(int i=1;i<=n*n;++i) {
        if(g[i].size() != 1) continue;
        int ok = 0;
        for(int j=1;j<=1000;++j) {
            if(mp[j] == g[i].size()) {
                ok = 1;
                for(int k : g[i]) {
                    ans[k] = j;
                }
                mp[j] = 0;
                break;
            }
        }
        if(!ok) {
            for(int j=1;j<=1000;++j) {
                if(mp[j] > g[i].size()) {
                    ok = 1;
                    for(int k : g[i]) {
                        ans[k] = j;
                    }
                    mp[j] -= g[i].size();
                    break;
                }
            }
        }
        if(!ok) {
            okk = 0;
            break;
        }
    }
    if(!okk) {cout << "NO\n";return 0;}

    cout << "YES\n";
    ii {ji cout<<ans[(i-1)*n+j]<<" ";cout<<endl;}
}