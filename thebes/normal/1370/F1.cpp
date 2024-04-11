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
typedef tuple<int,int,int> t3;

#define pb push_back
#define mt make_tuple
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 1005;
int T, N, i, x, y, vis[MN], dep[MN], par[MN], bad[MN], nxt, rt, len, md;
vi adj[MN], vec, acc; pii tmp;

inline pii qu(){
    if(acc.empty()) return make_pair(-1,-1);
    printf("? %d ",acc.size());
    for(auto v : acc)
        printf("%d ",v);
    printf("\n");
    fflush(stdout);
    int x, d;
    scanf("%d%d",&x,&d);
    if(x==-1&&d==-1) exit(0);
    else return make_pair(x,d);
}

void dfs(int n,int p){
    vec.pb(n); md=max(md,dep[n]);
    for(auto v : adj[n]){
        if(v==p) continue;
        dep[v] = dep[n]+1;
        par[v] = n;
        dfs(v, n);
    }
}

map<int,int> cc;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N); md=0;
        cc.clear();
        for(i=1;i<=N;i++)
            adj[i].clear();
        for(i=1;i<N;i++){
            scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        acc.clear();
        for(i=1;i<=N;i++)
            acc.pb(i);
        tmp=qu();
        rt=tmp.F, len=tmp.S;
        dep[rt]=0; par[rt]=-1;
        vec.clear();
        dfs(rt, -1);
        int lo=min(md,(int)ceil(len/2.0))+1, hi=min(md,len)+1;
        while(lo<hi){
            int mid = (lo+hi)>>1;
            acc.clear();
            for(auto v : vec){
                if(dep[v]>=mid) acc.pb(v);
            }
            tmp=qu();
            cc[mid]=tmp.F;
            if(tmp.S==len) lo=mid+1;
            else hi=mid;
        }
        lo--;
        int ot;
        if(!cc.count(lo)){
            acc.clear();
            for(auto v : vec){
                if(dep[v]==lo) acc.pb(v);
            }
            ot = qu().F;
        }
        else ot = cc[lo];
        int hm = len-lo;
        memset(bad,0,sizeof(bad));
        if(!hm) printf("! %d %d\n",rt,ot);
        else{
            acc.clear();
            int cur = ot;
            while(~cur){
                bad[cur]=1;
                cur=par[cur];
            }
            for(i=1;i<=N;i++){
                if(dep[i]==hm&&!bad[i]) acc.pb(i);
            }
            if(acc.size()==1) printf("! %d %d\n",ot,acc[0]);
            else printf("! %d %d\n",ot,qu().F);
        }
        fflush(stdout);
        string s;
        cin >> s;
        if(s=="Incorrect") exit(0);
    }
    return 0;
}