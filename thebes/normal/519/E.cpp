#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
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
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const int MN = 1e5+5, LG = 20;
int N, M, i, j, x, y, sp[MN][LG], dep[MN], sz[MN], mid;
vi adj[MN];

void go(int n,int p,int d){
    sp[n][0] = p; dep[n] = d; sz[n] = 1;
    for(auto v : adj[n]){
        if(v==p) continue;
        go(v, n, d+1);
        sz[n] += sz[v];
    }
}

int adv(int n,int d){
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=d){
            d -= (1<<i);
            n = sp[n][i];
        }
    }
    return n;
}

int dist(int x,int y){
    int ret = 0;
    if(dep[x]<dep[y]) swap(x,y);
    ret += dep[x]-dep[y];
    x = adv(x,dep[x]-dep[y]);
    if(x==y) return ret;
    for(int i=LG-1;i>=0;i--){
        if(sp[x][i]!=sp[y][i]){
            ret += (1<<(i+1));
            x = sp[x][i];
            y = sp[y][i];
        }
    }
    return ret+2;
}

int main(){
    scanf("%d",&N);
    fox(i,1,N-1){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    go(1,0,1);
    fox(j,1,LG-1){
        fox(i,1,N)
            sp[i][j]=sp[sp[i][j-1]][j-1];
    }
    scanf("%d",&M);
    fox(z,1,M){
        scanf("%d%d",&x,&y);
        int d = dist(x,y);
        if(d==0) pr(N);
        else if(d&1) pr(0);
        else if(dep[x]==dep[y]){
            mid = adv(x,d/2-1);
            int tmp = sz[mid];
            mid = adv(y,d/2-1);
            pr(N-tmp-sz[mid]);
        }
        else{
            if(dep[x]<dep[y]) swap(x,y);
            mid = adv(x,d/2-1);
            int tmp = sz[mid];
            mid = sp[mid][0];
            pr(sz[mid]-tmp);
        }
    }
    return 0;
}