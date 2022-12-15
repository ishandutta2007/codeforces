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

const int MN = 1005;
int N, M, Q, i, j, x, y, dx[]={-1,1,0,0}, dy[]={0,0,-1,1}, dis[MN*MN], ds[MN*MN], nxt; ll t;
string s[MN]; queue<int> q; vector<pii> elem[MN*MN];
inline int id(int x,int y){return x*M+y;}

void go(int x,int y,int cc){
    elem[cc].pb({x,y});
    for(int k=0;k<4;k++){
        int nx=x+dx[k], ny=y+dy[k];
        if(nx<0||nx>=N||ny<0||ny>=M) continue;
        if(s[nx][ny]==s[x][y]&&ds[id(nx,ny)]==-1){
            ds[id(nx,ny)]=cc;
            go(nx,ny,cc);
        }
    }
}

int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for(i=0;i<N;i++)
        cin >> s[i];
    memset(ds,-1,sizeof(ds));
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(ds[id(i,j)]==-1){
                ds[id(i,j)]=++nxt;
                go(i,j,nxt);
                if(elem[nxt].size()>1){
                    dis[nxt]=0;
                    q.push(nxt);
                }
                else dis[nxt]=-1;
            }
        }
    }
    int cur=0;
    while(q.size()){
        int sz = q.size();
        while(sz--){
            x=q.front(); q.pop();
            for(auto v : elem[x]){
                for(int k=0;k<4;k++){
                    int nx=v.F+dx[k], ny=v.S+dy[k];
                    if(nx<0||nx>=N||ny<0||ny>=M) continue;
                    int ot = ds[id(nx,ny)];
                    if(dis[ot]==-1){
                        dis[ot]=cur+1;
                        q.push(ot);
                    }
                }
            }
        }
        cur++;
    }
    for(;Q;Q--){
        scanf("%d%d%lld",&x,&y,&t);
        x--, y--;
        int tt = dis[ds[id(x,y)]];
        if(tt==-1||t<=tt) printf("%c\n",s[x][y]);
        else{
            ll swp = (t-tt)&1;
            if(s[x][y]=='0') printf("%c\n","01"[swp]);
            else printf("%c\n","10"[swp]);
        }
    }
    return 0;
}