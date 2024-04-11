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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;


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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    Dinic dn(n+2);
    int st = n, en = n+1;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> b(n);
    rep(i,n)cin>>b[i];
    ll ans = 0;
    rep(i,n){
        if(b[i]>0){
            ans += b[i];
            dn.addedge(st, i, b[i]);
        } else {
            dn.addedge(i, en, -b[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        set<int> st;
        for(int j=i-1;j>=0;--j){
            if(a[i]%a[j]==0 && !st.count(a[j])){
                dn.addedge(i, j, inf);
                REP(k,1,100){
                    if(a[j]%k==0)st.insert(k);
                }
            }
        }
    }
    cout<<ans - dn.max_flow(st, en)<<endl;
    return 0;
}