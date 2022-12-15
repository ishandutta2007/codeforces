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

const int MN = 1e5+5;
int t, n, i, j, p[MN], q[MN], a[3], nxt, vis[MN];
set<int> adj[MN]; map<pii,int> in; vi tree[MN];
void go(int n,int par){
    for(auto v:tree[n]){
        if(v!=par) go(v,n);
    }
    q[++nxt]=n;
}
void go2(int n){
    p[++nxt]=n; vis[n] = 1;
    for(auto v : adj[n]){
        if(!vis[v]) go2(v);
    }
}
int main(){
    scanf("%d",&t);
    fox(z,1,t){
        scanf("%d",&n);
        fox(i,1,n) tree[i].clear(), adj[i].clear();
        in.clear(); nxt=0;
        fox(i,1,n-2){
            fox(j,0,2) scanf("%d",&a[j]);
            fox(j,0,2){
                int x = a[j], y = a[(j+1)%3];
                if(x>y) swap(x,y);
                if(in.count({x,y})){
                    adj[x].erase(y);
                    adj[y].erase(x);
                    int ot = in[{x,y}];
                    tree[ot].pb(i);
                    tree[i].pb(ot);
                }
                else{
                    in[{x,y}]=i;
                    adj[x].insert(y);
                    adj[y].insert(x);
                }
            }
        }
        go(1,0);
        fox(i,1,n) vis[i]=0;
        nxt = 0;
        go2(1);
        fox(i,1,n) printf("%d ",p[i]);
        printf("\n");
        fox(i,1,n-2) printf("%d ",q[i]);
        printf("\n");
    }
    return 0;
}