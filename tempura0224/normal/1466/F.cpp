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

vector<int> v[505050];
int used[505050];

void dfs(int x){
    queue<int> q;
    q.push(x);
    while(q.size()){
        int t=q.front();q.pop();
        for(auto to: v[t]){
            if(!used[to]){
                used[to]=1;
                q.push(to);
            }
        }
    }
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> ans;
    UnionFind uf(m);
    rep(i,n){
        int k;
        cin>>k;
        if(k==1){
            int x;
            cin>>x;
            --x;
            if(!used[x]){
                ans.push_back(i+1);
                used[x]=1;
                dfs(x);
            }
        } else {
            int x, y;
            cin >> x >> y;
            --x;--y;
            if(used[x]&&used[y])continue;
            if(uf.unite(x, y)){
                ans.push_back(i+1);
                v[x].push_back(y);
                v[y].push_back(x);
                if(used[y]){
                    used[x]=1;
                    dfs(x);
                } else if(used[x]){
                    used[y]=1;
                    dfs(y);
                }
            }
        }
    }
    int num = 1;
    rep(i,ans.size()){
        num <<= 1;
        if(num>=mod)num-=mod;
    }
    cout<<num<<" "<<ans.size()<<endl;
    for(auto e: ans)cout<<e<<" ";
    cout<<endl;
    return 0;
}