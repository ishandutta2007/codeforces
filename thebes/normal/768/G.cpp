#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 1e5+5;
int N, i, x, y, lo, hi, id[MN], sz[MN], ans[MN], nxt, rt, f[MN];
vi adj[MN]; multiset<int> path, ot, sub[MN];

int init(int n,int p){
    sz[n]=1;
    for(auto v : adj[n]){
        if(v==p) continue;
        sz[n] += init(v, n);
    }
    ot.insert(sz[n]);
    return sz[n];
}

void st(int n,int p,bool sh){
    if(sh) ot.insert(sz[n]);
    else ot.erase(ot.find(sz[n]));
    for(auto v : adj[n]){
        if(v==p) continue;
        st(v,n,sh);
    }
}

void solve(int n,int p){
    ot.erase(ot.find(sz[n]));
    path.insert(sz[n]);
    pii big(-1,-1);
    for(auto v : adj[n]){
        if(v==p) continue;
        if(sz[v]>big.first)
            big={sz[v],v};
    }
    for(auto v : adj[n]){
        if(v==p||v==big.second) continue;
        solve(v,n); st(v,n,1);
    }
    if(big.second==-1) id[n]=++nxt;
    else solve(big.second,n),id[n]=id[big.second];
    for(auto v : adj[n]){
        if(v==p||v==big.second) continue;
        st(v,n,0);
    }
    if(big.first>=N-sz[n]){
        vi tr;
        for(auto v : adj[n]){
            if(v==big.second||v==p) continue;
            tr.pb(sz[v]);
        }
        if(p) tr.pb(N-sz[n]);
        sort(tr.begin(),tr.end(),[](int i,int j){return i>j;});
        if(tr.empty()){
            ans[n] = big.first;
        }
        else{
            lo=1, hi=big.first;
            while(lo<hi){
                int m = (lo+hi)>>1;
                int a = big.first-m, b = m-tr.back();
                auto it = sub[id[n]].lower_bound(a);
                if(it!=sub[id[n]].end()&&*it<=b&&tr[0]<=m) hi=m;
                else lo=m+1;
            }
            ans[n] = lo;
        }
        f[n]=1;
    }
    else if(p){
        vi tr;
        for(auto v : adj[n]){
            if(v==p) continue;
            tr.pb(sz[v]);
        }
        sort(tr.begin(),tr.end(),[](int i,int j){return i>j;});
        if(tr.empty()){
            ans[n] = N-sz[n];
        }
        else{
            lo=1, hi=N-sz[n];
            while(lo<hi){
                int m = (lo+hi)>>1;
                int a = N-sz[n]-m, b = m-tr.back();
                auto it = ot.lower_bound(a);
                auto it2 = path.lower_bound(sz[n]+a);
                if(tr[0]<=m&&((it!=ot.end()&&*it<=b)||(it2!=path.end()&&*it2<=sz[n]+b))) hi=m;
                else lo=m+1;
            }
            ans[n] = lo;
        }
    }
    for(auto v : adj[n]){
        if(v==p||v==big.second) continue;
        for(auto u : sub[id[v]])
            sub[id[n]].insert(u);
    }
    sub[id[n]].insert(sz[n]);
    path.erase(path.find(sz[n]));
}

int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
        if(!x||!y) rt=x?x:y;
    }
    init(rt,0);
    solve(rt,0);
    for(i=1;i<=N;i++)
        printf("%d\n",ans[i]);
    return 0;
}