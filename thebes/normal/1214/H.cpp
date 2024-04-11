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
    template<class T>
    void __(const multiset<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
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

const int MN = 2e5+5;
int N, K, i, x, y, f, ans[MN];
pii a[MN][3];
vi adj[MN];

int dfs(int n,int p){
    for(auto v : adj[n]){
        if(v==p) continue;
        pii c={dfs(v,n)+1,v};
        for(int i=0;i<3;i++){
            if(c.first>a[n][i].first){
                for(int j=2;j>i;j--) a[n][j]=a[n][j-1];
                a[n][i]=c;
                break;
            }
        }
    }
    return a[n][0].first;
}

void ree(int n,int p,int d){
    for(int i=0;i<3;i++){
        if(d>a[n][i].first){
            for(int j=2;j>i;j--) a[n][j]=a[n][j-1];
            a[n][i]={d,p};
            break;
        }
    }
    for(auto v : adj[n]){
        if(v==p) continue;
        if(v==a[n][0].second) ree(v,n,max(d,a[n][1].first)+1);
        else ree(v,n,max(d,a[n][0].first)+1);
    }
    if(a[n][1].first&&a[n][2].first&&a[n][1].first+a[n][2].first+1>=K) f=1;
}

void solve(int n,int p,int u,int d){
    ans[n] = u;
    int t = 0;
    if(p&&a[n][0].second==p) t=1;
    else if(p&&a[n][1].second==p) t=2;
    for(auto v : adj[n]){
        if(v==p) continue;
        if(t==0){
            if(v==a[n][0].second) solve(v,n,(u+d+K)%K,d);
            else solve(v,n,(u-d+K)%K,-d);
        }
        else if(t==1){
            solve(v,n,(u+d+K)%K,d);
        }
        else{
            if(v==a[n][0].second) solve(v,n,(u+d+K)%K,d);
            else solve(v,n,(u-d+K)%K,-d);
        }
    }
}

int main(){
    scanf("%d%d",&N,&K);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    ree(1,0,0);
    if(f&&K!=2) printf("No\n");
    else{
        for(i=1;i<=N;i++) if(adj[i].size()==1) break;
        solve(i,0,0,1);
        printf("Yes\n");
        for(i=1;i<=N;i++) printf("%d ",ans[i]+1);
        printf("\n");
    }
    return 0;
}