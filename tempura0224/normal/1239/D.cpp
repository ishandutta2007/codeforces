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

struct StronglyConnectedComponents{
    vector<int> used,cmp,vs;
    vector<vector<int>> v,rv;
    StronglyConnectedComponents(int n):used(n),cmp(n,-1),v(n),rv(n){}

    void add_edge(int x,int y){
        v[x].push_back(y);
        rv[y].push_back(x);
    }
    void dfs(int x){
        used[x]=true;
        for(auto to:v[x])if(!used[to])dfs(to);
        vs.push_back(x);
    }

    void rdfs(int x,int k){
        cmp[x]=k;
        for(auto to:rv[x])if(cmp[to]==-1)rdfs(to,k);
    }

    int scc(){
        rep(i,used.size())if(!used[i])dfs(i);
        reverse(vs.begin(),vs.end());
        int k=0;
        for(auto x:vs)if(cmp[x]==-1)rdfs(x,k++);
        return k;
    }
    void build(vector<vector<int>> &g){
        int k=scc();
        g.resize(k);
        set<pair<int,int>> used;
        rep(i,v.size()){
            for(auto& to:v[i]){
                int x=cmp[i],y=cmp[to];
                if(x==y||used.count({x,y}))continue;
                g[x].push_back(y);
                used.emplace(x,y);
            }
        }
    }
};

void dfs(vector<vector<int>>& g, vector<int>& used, int x, bool& ok){
    if(!ok&&g[x].empty())used[x]=1,ok=true;
    else used[x]=0;
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        StronglyConnectedComponents scc(n);
        rep(i,m){
            int x,y;
            scanf("%d%d",&x,&y);
            --x;--y;
            if(x==y)continue;
            scc.add_edge(x,y);
        }
        vector<vector<int>> g;
        scc.build(g);
        vector<int> cat, res;
        vector<int> used(n,-1);
        bool ok=false;
        rep(i,g.size())if(used[i]==-1)dfs(g,used,i,ok);
        rep(i,n){
            if(used[scc.cmp[i]]==0){
                cat.emplace_back(i+1);
            }
            else if(used[scc.cmp[i]]==1){
                res.emplace_back(i+1);
            }
            else assert(false);
        }
        assert(res.size()+cat.size()==n);
        if(res.empty()||cat.empty()){
            printf("No\n");
        }
        else {
            printf("Yes\n");
            printf("%d %d\n",(int)res.size(),(int)cat.size());
            for(auto e:res){
                printf("%d ",e);
            }
            printf("\n");
            for(auto e:cat){
                printf("%d ",e);
            }
            printf("\n");
        }
    }
    return 0;
}