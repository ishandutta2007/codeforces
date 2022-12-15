#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1e5+5;
set<int> mo[MN];
int N, M, i, x, y, cmp[MN], dep[MN], nxt;
vi adj[MN]; pii e[MN];

void go(int n,int p,int d){
    cmp[n] = nxt; dep[n] = d;
    for(auto v : adj[n]) if(v!=p) go(v,n,d+1);
}

int main(){
    for(scanf("%d",&N),i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
        e[i]={x,y};
    }
    int mx=0, rt=0;
    for(i=1;i<=N;i++) if(adj[i].size()>mx) mx=adj[i].size(),rt=i;
    for(auto v : adj[rt]){
        ++nxt; go(v,rt,1);
    }
    for(scanf("%d",&M);M;M--){
        scanf("%d%d",&i,&x);
        if(i==3){
            scanf("%d",&y);
            if(dep[x]>dep[y]) swap(x,y);
            if(cmp[x]==cmp[y]){
                auto it = mo[cmp[x]].lower_bound(dep[x]+1);
                if(it==mo[cmp[x]].end()||*it>dep[y])printf("%d\n",dep[y]-dep[x]);
                else printf("-1\n");
            }
            else{
                auto it = mo[cmp[x]].lower_bound(0);
                auto it2 = mo[cmp[y]].lower_bound(0);
                if((it==mo[cmp[x]].end()||*it>dep[x])&&(it2==mo[cmp[y]].end()||*it2>dep[y])) printf("%d\n",dep[x]+dep[y]);
                else printf("-1\n");
            }
        }
        else{
            x=dep[e[x].first]>dep[e[x].second]?e[x].first:e[x].second;
            if(i==1) mo[cmp[x]].erase(dep[x]);
            else mo[cmp[x]].insert(dep[x]);
        }
    }
    return 0;
}