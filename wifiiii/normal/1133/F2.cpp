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

const int maxn = 200005;
int par[maxn],deg[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
struct edge {
    int u,v,w;
    bool operator < (const edge & e) const {
        return w > e.w;
    }
}es[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,d;
    cin>>n>>m>>d;

    ij cin>>es[i].u>>es[i].v,es[i].w=0;

    ij if(es[i].u==1 || es[i].v==1) es[i].w=1;
    sort(es+1,es+1+m);
    ii par[i]=i;
    int mx=0;
    ij {
        int x=find(es[i].u),y=find(es[i].v);
        if(x==y) continue;
        par[x]=y;
        mx+=es[i].w;
    }

    int mn=0;
    ij if(es[i].u==1 || es[i].v==1) es[i].w=-1;
    sort(es+1,es+1+m);
    ii par[i]=i;
    ij {
        int x=find(es[i].u),y=find(es[i].v);
        if(x==y) continue;
        par[x]=y;
        if(es[i].w==-1) es[i].w=1;
        mn+=es[i].w;
    }
    assert(mn <= mx);
    if(mn <= d && d <= mx) {
        d-=mn;
        for(int i=1;i<=m && d;++i) {
            if(es[i].w >= 0) continue;
            es[i].w = 1;
            --d;
        }
        vii ans;
        sort(es+1,es+1+m);
        ii par[i]=i;
        ij {
            int x=find(es[i].u),y=find(es[i].v);
            if(es[i].w==-1) assert(x==y);
            if(es[i].w==1) assert(x!=y);
            if(x==y) continue;
            ans.push_back({es[i].u,es[i].v});
            par[x]=y;
        }
        cout<<"YES\n";
        for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
    } else cout << "NO\n";
}