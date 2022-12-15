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

const int MN = 404, MM = 125;
int n, i, j, x, y, ds[5*MM*MM], dx[]={-1,1,0,0}, dy[]={0,0,-1,1}, dis[2*MN][2*MN], block[2*MN][2*MN]; pii s, e, tmp;
char dir[]={'L','R','D','U'}; vector<char> ans;

int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
inline void mv(int id,int dx,int dy){
    int nx=(!id?s.F:e.F)+dx,ny=(!id?s.S:e.S)+dy;
    if(nx>=0&&nx<2*MM&&ny>=0&&ny<2*MM&&block[nx][ny]) return;
    if(!id) s={nx,ny};
    else e={nx,ny};
}

inline void gen(pii src){
    queue<pii> q;
    memset(dis,-1,sizeof(dis));
    dis[src.F][src.S]=0; q.push(src);
    while(q.size()){
        pii cur=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=cur.F+dx[k], ny=cur.S+dy[k];
            if(nx<0||nx>2*MM||ny<0||ny>2*MM) continue;
            if(!block[nx][ny]&&dis[nx][ny]==-1){
                dis[nx][ny]=dis[cur.F][cur.S]+1;
                q.push({nx,ny});
            }
        }
    }
}

inline void trans(int d,int steps){
    while(steps--){
        mv(0,dx[d],dy[d]);
        mv(1,dx[d],dy[d]);
        ans.pb(dir[d]);
    }
}

int main(){
    scanf("%d%d%d%d%d",&s.F,&s.S,&e.F,&e.S,&n);
    s.F+=MM, s.S+=MM, e.F+=MM, e.S+=MM;
    for(i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        x+=MM, y+=MM;
        block[x][y]=1;
    }
    for(i=0;i<2*MM;i++){
        for(j=0;j<2*MM;j++)
            ds[i*(2*MM)+j]=i*(2*MM)+j;
    }
    for(i=0;i<2*MM;i++){
        for(j=0;j<2*MM;j++){
            if(block[i][j]) continue;
            int id=i*2*MM+j;
            for(int k=0;k<4;k++){
                int nx=i+dx[k], ny=j+dy[k];
                if(nx<0||nx>2*MM||ny<0||ny>2*MM) continue;
                if(!block[nx][ny]){
                    int ot=nx*2*MM+ny;
                    if(fnd(id)!=fnd(ot))
                        ds[fnd(id)]=fnd(ot);
                }
            }
        }
    }
    int hm=2*MM-1;
    const int INF = 1500;
    if(fnd(s.F*2*MM+s.S)!=fnd(e.F*2*MM+e.S)||!n) printf("-1\n");
    else if(fnd(s.F*2*MM+s.S)==fnd(hm*2*MM+hm)){
        gen(s); vi op; pii cur={hm,hm};
        while(cur!=s){
            for(int k=0;k<4;k++){
                int nx=cur.F+dx[k], ny=cur.S+dy[k];
                if(nx<0||nx>2*MM||ny<0||ny>2*MM) continue;
                if(dis[nx][ny]+1==dis[cur.F][cur.S]){
                    op.pb(k^1);
                    cur={nx,ny};
                    break;
                }
            }
        }
        reverse(op.begin(),op.end());
        for(auto v : op){
            mv(0,dx[v],dy[v]);
            mv(1,dx[v],dy[v]);
            ans.pb(dir[v]);
        }
        op.clear();
        for(i=0;i<2*MM+10;i++){
            mv(0,dx[1],dy[1]);
            mv(1,dx[1],dy[1]);
            ans.pb(dir[1]);
            mv(0,dx[3],dy[3]);
            mv(1,dx[3],dy[3]);
            ans.pb(dir[3]);
        }
        if(e.F>=0&&e.F<hm&&e.S>=0&&e.S<hm){
            gen(e); op.clear(); pii cur={hm,hm};
            while(cur!=e){
                for(int k=0;k<4;k++){
                    int nx=cur.F+dx[k], ny=cur.S+dy[k];
                    if(nx<0||nx>2*MM||ny<0||ny>2*MM) continue;
                    if(dis[nx][ny]+1==dis[cur.F][cur.S]){
                        op.pb(k^1);
                        cur={nx,ny};
                        break;
                    }
                }
            }
            reverse(op.begin(),op.end());
            for(auto v : op){
                mv(0,dx[v],dy[v]);
                mv(1,dx[v],dy[v]);
                ans.pb(dir[v]);
            }
        }
        pii a={min(s.F,e.F),min(s.S,e.S)};
        pii b={max(s.F,e.F),max(s.S,e.S)};
        if(e.F<s.F){
            pii cell(-1,-1);
            for(i=0;i<2*MM;i++){
                for(j=0;j<2*MM;j++){
                    if(block[i][j]&&i>cell.first)
                        cell={i,j};
                }
            }
            int DX = e.F-cell.F, DY = e.S-cell.S, DC = s.F-e.F-1;
            trans(2,DY);
            trans(0,DX+DC);
            trans(1,DX+DC);
            trans(3,DY);
        }
        else if(e.F>s.F){
            pii cell(10000,10000);
            for(i=0;i<2*MM;i++){
                for(j=0;j<2*MM;j++){
                    if(block[i][j]&&i<cell.first)
                        cell={i,j};
                }
            }
            int IDX = INF;
            trans(0,IDX);
            int DX = cell.F-e.F, DY = e.S-cell.S, DC = e.F-s.F-1;
            trans(2,DY);
            trans(1,DX+DC);
            trans(0,DX+DC);
            trans(3,DY);
            trans(1,IDX);
        }
        if(e.S<s.S){
            pii cell(-1,-1);
            for(i=0;i<2*MM;i++){
                for(j=0;j<2*MM;j++){
                    if(block[i][j]&&i>cell.second)
                        cell={i,j};
                }
            }
            int DX = e.F-cell.F, DY = e.S-cell.S, DC = s.S-e.S-1;
            trans(0,DX);
            trans(2,DY+DC);
            trans(3,DY+DC);
            trans(1,DX);
        }
        else if(s.S<e.S){
            pii cell(10000,10000);
            for(i=0;i<2*MM;i++){
                for(j=0;j<2*MM;j++){
                    if(block[i][j]&&i<cell.second)
                        cell={i,j};
                }
            }
            int IDY = INF;
            trans(2,IDY);
            int DX = e.F-cell.F, DY = cell.S-e.S, DC = e.S-s.S-1;
            trans(0,DX);
            trans(3,DY+DC);
            trans(2,DY+DC);
            trans(1,DX);
            trans(2,IDY);
        }
        for(auto v : ans)
            printf("%c",v);
        pr();
    }
    else{
        queue<pii> q;
        while(s!=e){
            gen(e);
            for(int k=0;k<4;k++){
                int nx=s.F+dx[k], ny=s.S+dy[k];
                if(nx<0||nx>2*MM||ny<0||ny>2*MM) continue;
                if(dis[nx][ny]+1==dis[s.F][s.S]){
                    mv(1,dx[k],dy[k]);
                    mv(0,dx[k],dy[k]);
                    ans.pb(dir[k]);
                    break;
                }
            }
        }
        for(auto v : ans)
            printf("%c",v);
        pr();
    }
}