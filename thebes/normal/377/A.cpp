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

const int MN = 505;
int n, m, k, i, j, vs[MN][MN], dx[]={-1,1,0,0}, dy[]={0,0,1,-1};
string s[MN]; vector<pii> adj[MN][MN]; queue<pii> q;

void go(int x,int y){
    vs[x][y]=1;
    for(int d=0;d<4;d++){
        int nx=x+dx[d], ny=y+dy[d];
        if(nx<=n&&nx>=1&&ny<=m&&ny>=1){
            if(s[nx][ny]=='.'&&!vs[nx][ny]){
                adj[x][y].pb({nx,ny});
                go(nx,ny);
            }
        }
    }
}

void dfs(int x,int y){
    for(auto v : adj[x][y]){
        dfs(v.first,v.second);
    }
    if(k){
        s[x][y]='X';
        k--;
    }
}

int main(){
    for(scanf("%d%d%d\n",&n,&m,&k),i=1;i<=n;i++){
        cin >> s[i];
        s[i].insert(s[i].begin(),' ');
    }
    pii rt(-1,-1);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!vs[i][j]&&s[i][j]=='.'){
                go(i,j);
                rt={i,j};
                break;
            }
        }
        if(rt.first!=-1) break;
    }
    dfs(rt.first,rt.second);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%c",s[i][j]);
        }
        pr();
    }
    return 0;
}