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

#define int long long
const int MN = 2002, mod = 1e9+7;
int N, M, Q, i, j, x, y, w, ans, len[MN], ww[MN], sz=-1, wew;
vector<pii> adj[MN];

struct idk{int x, y, w;}ln[MN], ed[MN]; pll stk[MN];
struct pq{bool operator()(idk &i,idk &j){return i.w-wew*i.y<j.w-wew*j.y;}};
priority_queue<idk,vector<idk>,pq> q;

inline ld inter(pll i,pll j){
    return (j.S-i.S)/(ld)(i.F-j.F);
}

signed main(){
    scanf("%lld%lld%lld",&N,&M,&Q);
    for(i=1;i<=M;i++){
        scanf("%lld%lld%lld",&x,&y,&w);
        adj[x].pb({y,w});
        adj[y].pb({x,w});
        ed[i]={x,y,w};
    }
    for(i=1;i<=M;i++){
        wew = ed[i].w;
        memset(len,-1,sizeof(len));
        q.push({1,0,0});
        while(q.size()){
            idk cur=q.top(); q.pop();
            if(len[cur.x]!=-1) continue;
            len[cur.x] = cur.y;
            ww[cur.x] = cur.w;
            for(auto v : adj[cur.x]){
                if(~len[v.F]) continue;
                q.push({v.F,cur.y+1,cur.w+v.S});
            }
        }
        for(j=1;j<=M;j++){
            if(ed[j].w==wew){
                x=ed[j].x, y=ed[j].y, w=ed[j].w;
                if(len[x]<len[y]) swap(x,y);
                if(1LL*(len[x]-len[y])*wew>ww[x]-ww[y]) ln[j]={len[y], ww[y], w};
                else ln[j]={len[x], ww[x], w};
            }
        }
    }
    for(i=1;i<=M;i++){
        ll tmp = 0;
        for(j=1;j<=M;j++){
            if(ln[j].x<=i) tmp=max(tmp,1LL*ln[j].w*(i-ln[j].x)+ln[j].y);
        }
        ans = (ans+tmp)%mod;
    }
    sort(ln+1,ln+M+1,[](idk i,idk j){return i.w<j.w;});
    for(i=1;i<=M;i=j){
        ll it = -(1LL<<60);
        for(j=i;j<=M&&ln[j].w==ln[i].w;j++)
            it = max(it, (ll)ln[j].y-1LL*ln[j].x*ln[j].w);
        pll cur(ln[j-1].w,it);
        while(sz>=1){
            if(ceil(inter(stk[sz-1],stk[sz]))>floor(inter(stk[sz],cur))) sz--;
            else break;
        }
        stk[++sz]=cur;
    }
    ll pos = M+1;
    for(i=0;i<sz;i++){
        ll lim=min((ll)(inter(stk[i],stk[i+1])),(ll)Q);
        if(pos<=lim){
            ll nn = lim-pos+1;
            ll sm = (nn*((stk[i].F*pos%mod+stk[i].S)%mod)%mod+nn*(nn-1)/2%mod*stk[i].F%mod)%mod;
            ans = (ans+sm)%mod;
            pos = lim+1;
        }
        if(pos>Q) break;
    }
    if(pos<=Q){
        ll nn = Q-pos+1;
        ll sm = (nn*((stk[sz].F*pos%mod+stk[sz].S)%mod)%mod+nn*(nn-1)/2%mod*stk[sz].F%mod)%mod;
        ans = (ans+sm)%mod;
        pos = Q+1;
    }
    if(ans<0) ans+=mod;
    printf("%lld\n",ans);
    return 0;
}