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

const int MN = 5005;
int n, m, i, j, x, y, dis[MN][MN], ans;
vi adj[MN], sna;
vector<pii> a[MN], b[MN];

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
    }
    for(i=1;i<=n;i++){
        queue<int> q;
        q.push(i);
        memset(dis[i],-1,sizeof(dis[i]));
        dis[i][i] = 0;
        while(q.size()){
            x=q.front(); q.pop();
            if(a[i].size()<4) a[i].pb({x,dis[i][x]});
            else{
                pii hm(x,dis[i][x]);
                for(auto &v : a[i]) if(hm.second>v.second) swap(hm,v);
            }
            if(b[x].size()<4) b[x].pb({i,dis[i][x]});
            else{
                pii hm(i,dis[i][x]);
                for(auto &v : b[x]) if(hm.second>v.second) swap(hm,v);
            }
            for(auto v : adj[x]){
                if(dis[i][v]==-1){
                    dis[i][v]=dis[i][x]+1;
                    q.push(v);
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j) continue;
            if(dis[i][j]==-1) continue;
            for(auto v : b[i]){
                if(v.first==i||v.first==j) continue;
                for(auto w : a[j]){
                    if(w.first==i||w.first==j||w.first==v.first) continue;
                    if(v.second+w.second+dis[i][j]>ans){
                        ans=v.second+w.second+dis[i][j];
                        sna.clear();
                        sna.pb(v.first),sna.pb(i),sna.pb(j),sna.pb(w.first);
                    }
                }
            }
        }
    }
    for(auto v : sna) printf("%d ",v);
    printf("\n");
    return 0;
}