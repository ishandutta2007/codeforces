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
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 1e5+5, LG = 18;
int n, k, i, j, x, y, cur, ans, vis[MN], rev[MN], sp[MN][LG], dep[MN], nxt;
vi adj[MN]; set<int> s;

void dfs(int n,int p,int d){
    vis[n] = ++nxt; rev[nxt] = n;
    dep[n] = d;
    sp[n][0] = p;
    for(auto v : adj[n]) if(v!=p) dfs(v,n,d+1);
}

inline int dis(int x,int y){
    int ret = 0;
    if(dep[x]<dep[y]) swap(x,y);
    foxr(i,0,LG-1){
        if((1<<i)<=dep[x]-dep[y])
            x = sp[x][i], ret += (1<<i);
    }
    if(x==y) return ret;
    foxr(i,0,LG-1){
        if(sp[x][i]!=sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
            ret += (1<<(i+1));
        }
    }
    return ret+2;
}

inline void add(int x){
    int t = vis[x];
    if(s.size()){
        auto r = s.lower_bound(t);
        auto l = r;
        if(l==s.begin()) l=s.end();
        l--;
        if(r==s.end()) r=s.begin();
        cur += dis(rev[*l],x)+dis(rev[*r],x)-dis(rev[*l],rev[*r]);
    }
    s.insert(t);
}

inline void rem(int x){
    int t = vis[x];
    s.erase(t);
    if(s.size()){
        auto r = s.lower_bound(t);
        auto l = r;
        if(l==s.begin()) l=s.end();
        l--;
        if(r==s.end()) r=s.begin();
        cur -= dis(rev[*l],x)+dis(rev[*r],x)-dis(rev[*l],rev[*r]);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    fox(i,1,n-1){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,1);
    fox(j,1,LG-1){
        fox(i,1,n) sp[i][j]=sp[sp[i][j-1]][j-1];
    }
    for(i=1;i<=n;i++){
        if(cur/2<k){
            for(j++;j<=n;j++){
                add(j);
                if(cur/2>=k) break;
            }
        }
        ans = max(ans,j-i);
        rem(i);
    }
    printf("%d\n",ans);
    return 0;
}