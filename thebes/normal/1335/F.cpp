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
#define F first
#define S second

const int MN = 1e6+5;
int t, n, m, i, j, x, y;
string s[MN], d[MN]; vector<char> vs[MN], st[MN]; stack<pii> sta;
vector<vector<pii>> adj[MN];
vector<pii> cyc; set<int> ok;
vector<pair<pii,int>> go;

void dfs(int x,int y){
    sta.push({x,y});
    st[x][y]=1;
    vs[x][y]=1;
    pii nxt=adj[x][y][0];
    if(vs[nxt.F][nxt.S]){
        if(st[nxt.F][nxt.S]){
            while(sta.size()&&sta.top()!=nxt)
                cyc.pb(sta.top()),sta.pop();
            cyc.pb(sta.top());
        }
    }
    else dfs(nxt.F,nxt.S);
    st[x][y]=0;
    if(sta.size()&&sta.top()==make_pair(x,y)) sta.pop();
}

void dfs2(int x,int y,int sh,int p){
    if(sh==p) sh=0;
    if(s[x][y]=='0') ok.insert(sh);
    vs[x][y]=1;
    for(auto v : adj[x][y]){
        if(!vs[v.F][v.S]) dfs2(v.F,v.S,sh+1,p);
    }
}

int main(){
    for(scanf("%d",&t);t;t--){
        for(scanf("%d%d",&n,&m),i=0;i<n;i++)
            cin >> s[i];
        for(i=0;i<n;i++)
            cin >> d[i];
        for(i=0;i<n;i++){
            adj[i].clear();
            vs[i].clear();
            vs[i].resize(m);
            st[i].clear();
            st[i].resize(m);
            for(j=0;j<m;j++)
                adj[i].pb(vector<pii>());
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                pii ot;
                if(d[i][j]=='L') ot={i,j-1};
                else if(d[i][j]=='R') ot={i,j+1};
                else if(d[i][j]=='U') ot={i-1,j};
                else if(d[i][j]=='D') ot={i+1,j};
                adj[i][j].pb(ot);
            }
        }
        go.clear();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vs[i][j]) continue;
                cyc.clear();
                dfs(i,j);
                if(cyc.size())
                    go.pb({cyc[0],cyc.size()});
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                adj[i][j].clear();
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                pii ot;
                if(d[i][j]=='L') ot={i,j-1};
                else if(d[i][j]=='R') ot={i,j+1};
                else if(d[i][j]=='U') ot={i-1,j};
                else if(d[i][j]=='D') ot={i+1,j};
                adj[ot.first][ot.second].pb({i,j});
            }
        }
        int ans=0, ans2=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                vs[i][j]=0;
        }
        for(auto v : go){
            ok.clear();
            dfs2(v.F.F,v.F.S,0,v.S);
            ans+=(int)ok.size();
            ans2+=v.S;
        }
        printf("%d %d\n",ans2,ans);
    }
    return 0;
}