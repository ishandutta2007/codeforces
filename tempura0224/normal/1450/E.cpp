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


struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
   int size(int x){
       return -par[find(x)];
   }
};
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> x(m),y(m),z(m);
        rep(i,m){
            cin>>x[i]>>y[i]>>z[i];
            --x[i];--y[i];
        }
        UnionFind uf(2*n);
        rep(i,m){
            uf.unite(x[i],y[i]+n);
            uf.unite(x[i]+n,y[i]);
        }
        rep(i,n){
            if(uf.same(i,i+n)){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        vector<vector<pair<int,int>>> v(n);
        rep(i,m){
            if(z[i]==0){
                if(uf.same(0, x[i])){
                    v[x[i]].emplace_back(y[i],1);
                    v[y[i]].emplace_back(x[i],0);
                } else {
                    v[x[i]].emplace_back(y[i],0);
                    v[y[i]].emplace_back(x[i],1);
                }
            } else {
                if(uf.same(0, x[i])){
                    v[x[i]].emplace_back(y[i],1);
                    v[y[i]].emplace_back(x[i],-1);
                } else {
                    v[y[i]].emplace_back(x[i],0);
                    v[x[i]].emplace_back(y[i],0);
                }
            }
        }
        vector<int> dist(n,inf);
        dist[0]=0;
        rep(_,n){
            rep(x,n){
                for(auto to: v[x]){
                    dist[to.first] = min(dist[to.first],dist[x]+to.second);
                }
            }
        }
        bool can=true;
        rep(x,n){
            for(auto to: v[x]){
                if(dist[x]+to.second<dist[to.first]){
                    can=false;
                }
            }
        }
        if(!can){
            cout<<"NO"<<endl;
            return 0;
        }
        int ma = -1;
        vector<int> ans(n); 
        rep(st,n){
            rep(i,n)dist[i]=inf;
            dist[st]=0;
            rep(_,n){
                rep(x,n){
                    for(auto to: v[x]){
                        dist[to.first] = min(dist[to.first],dist[x]+to.second);
                    }
                }
            }
            bool nega=false;
            rep(i,n){
                if(dist[i]<0)nega=true;
            }
            if(nega)continue;
            int even=0, odd=0;
            rep(i,n){
                if(uf.same(0,i))even=max(even,2*dist[i]+2);
                else odd=max(odd,2*dist[i]+1);
            }
            int mi = uf.same(0,st) ? 2*dist[st]+2 : 2*dist[st]+1;
            int ret = max(odd,even)-mi;
            if(ret>ma){
                ma=ret;
                rep(i,n){
                    if(uf.same(0,i))ans[i] = 2*dist[i]+2;
                    else ans[i] = 2*dist[i]+1;
                }
            }
        }
        if(ma==-1){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            cout<<ma<<endl;
            rep(i,n)cout<<ans[i]<<" \n"[i+1==n];
        }
    }
    return 0;
}