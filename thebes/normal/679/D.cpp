#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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
const int MN = 404;
int N, M, i, j, x, y, dist[MN][MN], cnt[MN], z; double ans, res, _, wew[MN], kk, kkk[MN], r[MN];
double heh[MN][3]; set<pii> f; set<pii> ee; double e[MN*MN];
vi adj[MN]; queue<int> q; vi go;

void ini(int n){
    dist[n][n]=0; q.push(n);
    while(q.size()){
        int x = q.front(); q.pop();
        for(auto v : adj[x]){
            if(dist[n][v]==-1) dist[n][v]=dist[n][x]+1, q.push(v);
        }
    }
}

inline int h(pii x){return x.first*MN+x.second;}
inline int h(int x,int y){return x*MN+y;}

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    _ = 1.0/(double)N;
    memset(dist,-1,sizeof(dist));
    for(i=1;i<=N;i++) ini(i);
    for(j=1;j<=N;j++){
        memset(cnt,0,sizeof(cnt));
        memset(r,0,sizeof(r));
        memset(heh,0,sizeof(heh));
        for(i=1;i<=N;i++){
            for(auto v : adj[i])
                if(dist[j][v]) heh[i][dist[j][v]-dist[j][i]+1]+=_/(double)adj[v].size();
            cnt[dist[j][i]]++;
        }
        for(i=1;i<=N;i++){
            memset(wew,0,sizeof(wew));
            memset(kkk,0,sizeof(kkk));
            res=0;
            for(auto v : adj[i]) if(v!=j) kkk[dist[j][v]]+=_/(double)adj[v].size();
            for(int k=1;k<=N;k++){
                if(k==i) continue;
                for(int l=0;l<3;l++){
                    z = h(dist[j][k]-1+l,dist[i][k]);
                    if(!e[z]) go.pb(z);
                    e[z]=max(e[z],heh[k][l]);
                }
            }
            for(auto v : go) wew[v/MN]+=e[v],e[v]=0;
            go.clear();
            for(int k=1;k<=N;k++)
                if(cnt[k])r[k]=max(r[k],max(wew[k]+kkk[k],_));
        }
        double acc = 0;
        for(int k=1;k<=N;k++) acc+=r[k];
        ans = max(ans,_+acc);
    }
    printf("%.7lf\n",ans);
    return 0;
}