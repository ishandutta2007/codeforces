#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
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
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    template<class T1,class... T2>
    void print(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),print(t2...);else __("\n");}
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
const int MN = 505;
int id[MN][MN], n, m, i, j, k, a[MN][MN], sz[MN*MN], vs[MN*MN], heh, nxt, ans, c[MN*MN];
int dx[]={-1,1,0,0}, dy[]={0,0,1,-1};
void dfs(int x,int y){
    sz[nxt]++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>n) continue;
        if(!a[nx][ny]||id[nx][ny]) continue;
        id[nx][ny]=id[x][y]; dfs(nx,ny);
    }
}
vector<pii> vec;
inline void get(int x,int y,int r,int s){
    heh++;
    for(int i=max(0,x);i<=r;i++){
        for(int j=max(0,y);j<=s;j++){
            if(!id[i][j]) continue;
            vec.pb({i,j});
        }
    }
}

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        for(getchar(),j=1;j<=n;j++) if(getchar()=='.') a[i][j]=1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(id[i][j]||!a[i][j]) continue;
            id[i][j]=++nxt;
            dfs(i,j);
        }
    }
    for(i=1;i<=n-m+1;i++){
        memset(c,0,sizeof(c));
        vec.clear();
        get(i,1,i+m-1,m);
        for(auto v : vec) c[id[v.first][v.second]]++;
        vec.clear();
        get(i-1,1,i-1,m);
        get(i,m+1,i+m-1,m+1);
        get(i+m,1,i+m,m);
        int meh=0;
        for(auto v : vec){
            if(vs[id[v.first][v.second]]==heh) continue;
            vs[id[v.first][v.second]]=heh;
            meh+=sz[id[v.first][v.second]]-c[id[v.first][v.second]];
        }
        ans=max(ans,meh+m*m);
        for(j=2;j<=n-m+1;j++){
            int sm=0;
            vec.clear();
            get(i,j-1,i+m-1,j-1);
            for(auto v : vec) c[id[v.first][v.second]]--;
            vec.clear();
            get(i,j+m-1,i+m-1,j+m-1);
            for(auto v : vec) c[id[v.first][v.second]]++;
            vec.clear();
            get(i-1,j,i-1,j+m-1);
            get(i,j+m,i+m-1,j+m);
            get(i+m,j,i+m,j+m-1);
            get(i,j-1,i+m-1,j-1);
            for(auto v : vec){
                if(vs[id[v.first][v.second]]==heh) continue;
                vs[id[v.first][v.second]]=heh;
                sm+=sz[id[v.first][v.second]]-c[id[v.first][v.second]];
            }
            sm += m*m;
            ans = max(ans, sm);
        }
    }
    printf("%d\n",ans);
    return 0;
}