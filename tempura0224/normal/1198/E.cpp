#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

struct edge{int to;ll cap;int rev;};
struct Dinic{
private:
    int n;
    vector<vector<edge>> v;
    vector<int> dist,iter;
public:
    Dinic(int sz):n(sz),v(sz),dist(sz),iter(sz){}
    
    void addedge(int from,int to,ll cap){
        int x=v[to].size(),y=v[from].size();
        v[from].push_back({to,cap,x});
        v[to].push_back({from,0,y});
    }
    
    void bfs(int s){
        fill(dist.begin(),dist.end(),-1);
        queue<int> q;
        dist[s]=0;
        q.push(s);
        while(q.size()){
            int x=q.front();q.pop();
            rep(i,v[x].size()){
                edge &e=v[x][i];
                if(e.cap>0&&dist[e.to]<0){
                    dist[e.to]=dist[x]+1;
                    q.push(e.to);
                }
            }
        }
    }
    
    ll dfs(int x,int t,ll f){
        if(x==t)return f;
        for(int& i=iter[x];i<(int)v[x].size();++i){
            edge& e=v[x][i];
            if(e.cap>0&&dist[x]<dist[e.to]){
                ll d=dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap-=d;
                    v[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s,int t){
        ll flow=0;
        while(1){
            bfs(s);
            if(dist[t]<0)return flow;
            fill(iter.begin(),iter.end(),0);
            ll f;
            while((f=dfs(s,t,1LL<<62))>0)flow+=f;
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> xs,ys;
    int xl[m],yl[m],xr[m],yr[m];
    rep(i,m){
        cin>>xl[i]>>yl[i]>>xr[i]>>yr[i];
        ++xr[i];
        ++yr[i];
        xs.push_back(xl[i]);
        xs.push_back(xr[i]);
        ys.push_back(yl[i]);
        ys.push_back(yr[i]);
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    rep(i,m){
        xl[i]=lower_bound(xs.begin(),xs.end(),xl[i])-xs.begin();
        xr[i]=lower_bound(xs.begin(),xs.end(),xr[i])-xs.begin();
        yl[i]=lower_bound(ys.begin(),ys.end(),yl[i])-ys.begin();
        yr[i]=lower_bound(ys.begin(),ys.end(),yr[i])-ys.begin();
    }

    int X = xs.size();
    int Y = ys.size();
    int s = X+Y, t=X+Y+1;
    Dinic dn(X+Y+2);
    ll ans = 0;
    rep(i,X-1){
        dn.addedge(s, i, xs[i+1]-xs[i]);
    }
    rep(i,Y-1){
        dn.addedge(i+X, t,ys[i+1]-ys[i]);
    }
    rep(i,X-1)rep(j,Y-1){
        bool used=false;
        rep(k,m){
            if(xl[k]<=i&&i<xr[k]&&yl[k]<=j&&j<yr[k])used=true;
        }
        if(used)dn.addedge(i, X+j, 1ll<<50);
    }
    cout<<dn.max_flow(s, t)<<endl;
    return 0;
}