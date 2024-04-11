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
#define F first
#define S second

const int MN = 5e5+5, MK = 20;
int N, i, j, x, y, deg[1<<MK], ds[1<<MK], use[MN], msk, dn[1<<MK], cnt;
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
pii arr[MN]; vector<pii> adj[1<<MK], cyc[1<<MK];

void dfs(int n,int rt){
    while(adj[n].size()){
        pii ed = adj[n].back(); adj[n].pop_back();
        if(use[ed.S]) continue;
        use[ed.S] = 1;
        cyc[rt].pb(ed);
        dfs(ed.F, rt);
        return;
    }
}

void hm(int x){
    dn[x]=1; int cur=x;
    for(auto v : cyc[x]){
        int ot = v.F, id = v.S, swp=0;
        if((arr[id].F&msk)!=cur) swp=1;
        printf("%d %d ",(id<<1)-1+swp,(id<<1)-swp); cnt++;
        cur = ot;
        if(!dn[cur]){
            dfs(cur, cur);
            hm(cur);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d%d",&x,&y);
        arr[i]={x,y};
    }
    for(j=0;j<MK;j++){
        for(i=0;i<=msk;i++)
            deg[i]=0;
        msk|=(1<<j);
        for(i=0;i<=msk;i++)
            ds[i]=i;
        for(i=1;i<=N;i++){
            x=(arr[i].F&msk);
            y=(arr[i].S&msk);
            deg[x]++, deg[y]++;
            if(fnd(x)!=fnd(y)){
                ds[fnd(x)]=fnd(y);
            }
        }
        int ok = 1, rt = (arr[1].F&msk);
        for(i=1;i<=N;i++){
            x=(arr[i].F&msk);
            y=(arr[i].S&msk);
            if(deg[x]&1) ok=0;
            if(deg[y]&1) ok=0;
            if(fnd(rt)!=fnd(x)||fnd(rt)!=fnd(y)) ok=0;
            if(!ok) break;
        }
        if(!ok) break;
    }
    if(!j){
        printf("0\n");
        for(i=1;i<=2*N;i++)
            printf("%d ",i);
        printf("\n");
    }
    else{
        msk = 0;
        for(i=0;i<j;i++)
            msk |= (1<<i);
        for(i=1;i<=N;i++){
            x=(arr[i].F&msk);
            y=(arr[i].S&msk);
            adj[x].pb({y,i});
            adj[y].pb({x,i});
        }
        printf("%d\n",j);
        dfs(arr[1].F&msk,arr[1].F&msk);
        hm(arr[1].F&msk);
        printf("\n");
    }
    return 0;
}