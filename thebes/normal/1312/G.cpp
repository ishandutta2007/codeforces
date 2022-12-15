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

const int MN = 1e6+6;
int n, l, k, i, x, y, ok[MN], st[3*MN], lz[3*MN], dep[MN], ans[MN], vis[MN][2], nxt;
vector<pic> adj[MN]; vi qur;
stack<pii> stk; char ch;

void dfs(int n,int d){
    sort(adj[n].begin(),adj[n].end(),[](pic i,pic j){return i.second<j.second;});
    dep[n] = d; vis[n][0] = ++nxt;
    for(auto v : adj[n]){
        dfs(v.first, d+1);
    }
    l = max(l, d);
    vis[n][1] = ++nxt;
}

void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i] += lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i] = 0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i] = val;
        upd_lz(i,s,e);
    }
    else{
        if((s+e)/2<ss){
            upd(2*i+1,(s+e)/2+1,e,ss,se,val);
            upd_lz(2*i,s,(s+e)/2);
        }
        else if((s+e)/2>=se){
            upd(2*i,s,(s+e)/2,ss,se,val);
            upd_lz(2*i+1,(s+e)/2+1,e);
        }
        else{
            upd(2*i,s,(s+e)/2,ss,se,val);
            upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        }
        st[i]=min(st[2*i],st[2*i+1]);
    }
}

void sset(int i,int s,int e,int idx,int val){
    upd_lz(i,s,e);
    if(s!=e){
        if((s+e)/2<idx){
            sset(2*i+1,(s+e)/2+1,e,idx,val);
            upd_lz(2*i,s,(s+e)/2);
        }
        else{
            sset(2*i,s,(s+e)/2,idx,val);
            upd_lz(2*i+1,(s+e)/2+1,e);
        }
        st[i] = min(st[2*i],st[2*i+1]);
    }
    else st[i]=val;
}

int qu(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return min(qu(2*i,s,(s+e)/2,ss,se),qu(2*i+1,(s+e)/2+1,e,ss,se));
}

void solve(int n){
    if(ok[n]){
        upd(1,1,l,1,dep[n]-1,1);
        ans[n] = qu(1,1,l,1,dep[n]-1);
        while(stk.size()){
            x = stk.top().first;
            if(vis[x][1]<vis[n][0]) stk.pop();
            else break;
        }
        x = stk.top().first;
        ans[n] = min(ans[n], dep[n]-dep[x]+stk.top().second);
        stk.push({n,ans[n]});
        sset(1,1,l,dep[n],ans[n]+1);
    }
    else{
        while(stk.size()){
            x = stk.top().first;
            if(vis[x][1]<vis[n][0]) stk.pop();
            else break;
        }
        x = stk.top().first;
        ans[n] = dep[n]-dep[x]+stk.top().second;
        sset(1,1,l,dep[n],ans[n]);
    }
    for(auto v : adj[n]) solve(v.first);
}

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %c",&x,&ch);
        adj[x].pb({i,ch});
    }
    dfs(0, 1);
    for(scanf("%d",&k),i=1;i<=k;i++){
        scanf("%d",&x);
        ok[x] = 1;
        qur.pb(x);
    }
    stk.push({0,0});
    solve(0);
    for(auto v : qur) printf("%d ",ans[v]);
    printf("\n");
    return 0;
}