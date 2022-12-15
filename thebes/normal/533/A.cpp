#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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

const int MN = 5e5+5, LG = 20;
int N, M, K, i, j, x, y, a[MN], b[MN], h[MN], st[3*MN], lz[3*MN], ans=1<<30, lo, hi, bs[MN], rev[MN];
vi adj[MN]; vector<pii> qu[MN]; pii sp[MN];
map<int,int> mp;

inline int H(int x){return x>=0?a[x]:1<<30;}
inline pii cmp(pii&i,pii&j){
    if(H(i.first)<H(j.first)) return make_pair(i.first,H(i.second)<H(j.first)?i.second:j.first);
    else return make_pair(j.first,H(i.first)<H(j.second)?i.first:j.second);
}

void dfs(int n,int p){
    sp[n].first=n;
    if(p) sp[n]=cmp(sp[n],sp[p]);
    h[n]=min(h[n],a[n]);
    for(auto v : adj[n]){
        if(v==p) continue;
        h[v]=h[n];
        dfs(v,n);
    }
}

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i]+=lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i]=0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    if(ss>se) return;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){lz[i]=val;upd_lz(i,s,e);}
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i]=min(st[2*i],st[2*i+1]);
    }
}

int qur(int i,int s,int e){
    upd_lz(i,s,e);
    if(s==e) return st[i]<0?s:s-1;
    upd_lz(2*i+1,(s+e)/2+1,e);
    if(st[2*i+1]<0) return qur(2*i+1,(s+e)/2+1,e);
    else return qur(2*i,s,(s+e)/2);
}

void solve(int n,int p){
    if(qu[n].size()){
        vi vec, idx;
        sort(qu[n].begin(),qu[n].end(),[](pii i,pii j){return i.second<j.second;});
        for(auto v : qu[n]){
            vec.pb(v.second);
            auto it=mp.upper_bound(v.second);
            if(it!=mp.begin()) it--,idx.pb(it->second);
            else idx.pb(0);
            upd(1,1,M,1,bs[v.first],-1);
        }
        if(st[1]+(int)vec.size()>=0){
            int val=max(a[n],rev[qur(1,1,M)]);
            if(val<=vec[0]) ans=min(ans,val-a[n]);
        }
        for(i=0;i<vec.size();i++){
            upd(1,1,M,1,idx[i],1);
            if(st[1]+(int)vec.size()-i-1>=0){
                int val=max(a[n],rev[qur(1,1,M)]);
                if((i+1==vec.size()||val<=vec[i+1])&&val>=vec[i])
                    ans=min(ans,val-a[n]);
            }
        }
        for(i=0;i<idx.size();i++)
            upd(1,1,M,1,idx[i],-1);
        for(auto v : qu[n])
            upd(1,1,M,1,bs[v.first],1);
    }
    for(auto v : adj[n]){
        if(v!=p) solve(v,n);
    }
}

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++)
        scanf("%d",&a[i]);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(scanf("%d",&K),i=1;i<=K;i++)
        scanf("%d",&b[i]),mp[b[i]]=0;
    i=0; auto it=mp.begin();
    for(;it!=mp.end();it++)
        it->second=++i,rev[i]=it->first;
    M=mp.size();
    memset(sp,-1,sizeof(sp));
    h[1]=a[1]; dfs(1,0);
    for(i=1;i<=N;i++){
        pii hm=sp[i];
        qu[hm.first].pb({i,H(hm.second)});
    }
    for(i=1;i<=N;i++){
        auto it=mp.upper_bound(h[i]);
        if(it!=mp.begin()){
            it--,upd(1,1,M,1,it->second,1);
            bs[i]=it->second;
        }
    }
    for(i=1;i<=K;i++)
        upd(1,1,M,1,mp[b[i]],-1);
    solve(1,0);
    if(ans==1<<30) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}