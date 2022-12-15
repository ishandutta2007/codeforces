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

const int MN = 1e5+69, mod = 1e9+7;
struct nd{int sm, l, r, lz;}st[30000000];
int n, m, i, x, y, w, dis[MN], vs[MN], nxt, pw[MN]={1}, g[MN]={1}, lo, hi, mid, rt, par[MN];
vector<pii> adj[MN];

int init(int s,int e){
    int cur=++nxt;
    if(s!=e){
        st[cur].l=init(s,(s+e)/2);
        st[cur].r=init((s+e)/2+1,e);
    }
    return cur;
}

inline void upd_lz(int i,int s,int e){
    if(st[i].lz){
        st[i].sm=(st[i].lz==2)?g[e-s]:0;
        if(s!=e){
            if(!st[i].l) st[i].l=++nxt;
            if(!st[i].r) st[i].r=++nxt;
            st[st[i].l].lz=st[st[i].r].lz=st[i].lz;
        }
        st[i].lz=0;
    }
}

int upd(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    int cur = ++nxt;
    if(s>=ss&&e<=se){
        st[cur].lz = val;
        upd_lz(cur,s,e);
    }
    else{
        if((s+e)/2<ss){
            st[cur].r=upd(st[i].r,(s+e)/2+1,e,ss,se,val);
            st[cur].l=st[i].l;
            upd_lz(st[i].l,s,(s+e)/2);
        }
        else if((s+e)/2>=se){
            st[cur].l=upd(st[i].l,s,(s+e)/2,ss,se,val);
            st[cur].r=st[i].r;
            upd_lz(st[i].r,(s+e)/2+1,e);
        }
        else{
            st[cur].l=upd(st[i].l,s,(s+e)/2,ss,se,val);
            st[cur].r=upd(st[i].r,(s+e)/2+1,e,ss,se,val);
        }
        st[cur].sm=(st[st[cur].l].sm+1LL*st[st[cur].r].sm*pw[(s+e)/2-s+1])%mod;
    }
    return cur;
}

bool cmp(int i,int j,int s,int e){
    upd_lz(i,s,e); upd_lz(j,s,e);
    if(s==e) return st[i].sm<=st[j].sm;
    else if(st[st[i].r].sm==st[st[j].r].sm) return cmp(st[i].l,st[j].l,s,(s+e)/2);
    else return cmp(st[i].r,st[j].r,(s+e)/2+1,e);
}

int qu(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return st[i].sm;
    else if((s+e)/2<ss) return qu(st[i].r,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(st[i].l,s,(s+e)/2,ss,se);
    else return (qu(st[i].l,s,(s+e)/2,ss,se)+1LL*qu(st[i].r,(s+e)/2+1,e,ss,se)*pw[(s+e)/2-max(s,ss)+1])%mod;
}

struct pq{bool operator()(const pii&i,const pii&j){return !cmp(i.second,j.second,0,MN);}};
priority_queue<pii,vector<pii>,pq> q;

int main(){
    for(i=1;i<MN;i++){
        pw[i]=2LL*pw[i-1]%mod;
        g[i]=(g[i-1]+pw[i])%mod;
    }
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&w);
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    memset(dis,-1,sizeof(dis));
    int s, e;
    scanf("%d%d",&s,&e);
    dis[s]=init(0,MN);
    q.push({s,dis[s]}); par[s]=-1;
    while(q.size()){
        x = q.top().first; q.pop();
        if(vs[x]) continue;
        vs[x]=1;
        for(auto v : adj[x]){
            if(vs[v.first]) continue;
            rt = dis[x];
            lo = 0, hi = MN-v.second;
            while(lo<hi){
                mid = (lo+hi)>>1;
                if(qu(rt,0,MN,v.second,v.second+mid)==g[mid]) lo=mid+1;
                else hi=mid;
            }
            lo--;
            if(lo==-1) rt=upd(rt,0,MN,v.second,v.second,2);
            else{
                rt=upd(rt,0,MN,v.second,v.second+lo,1);
                rt=upd(rt,0,MN,v.second+lo+1,v.second+lo+1,2);
            }
            if(dis[v.first]==-1||!cmp(dis[v.first],rt,0,MN)){
                par[v.first]=x;
                dis[v.first]=rt;
                q.push({v.first,rt});
            }
        }
    }
    if(!vs[e]) printf("-1\n");
    else{
        printf("%d\n",qu(dis[e],0,MN,0,MN));
        vi ans; int cur = e;
        while(cur>0){
            ans.pb(cur);
            cur=par[cur];
        }
        reverse(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(auto v : ans) printf("%d ",v);
        printf("\n");
    }
    return 0;
}