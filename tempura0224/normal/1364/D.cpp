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

vector<int> v[101010];
int used[101010];
int d[101010], par[101010];
int c[101010];
void output(int x,int y){
    int xx=x, yy=y;
    vector<int> v1, v2;
    while(d[x]>d[y])v1.push_back(x),x=par[x];
    while(d[y]>d[x])v2.push_back(y),y=par[y];
    while(x!=y){
        v1.push_back(x);x=par[x];
        v2.push_back(y);y=par[y];
    }
    reverse(v1.begin(), v1.end());
    cout<<2<<endl;
    cout<<v1.size()+v2.size()+1<<endl;
    cout<<x+1<<" ";
    for(auto e:v1)cout<<e+1<<" ";
    for(auto e:v2)cout<<e+1<<" ";
    cout<<endl;
}
void dfs(int x, int p){
    used[x]=true;
    par[x]=p;
    for(auto to:v[x]){
        if(to!=p && used[to]){
            output(x, to);
            exit(0);
        }
        else if(to!=p){
            d[to]=d[x]+1;
            c[to]=-c[x];
            dfs(to,x);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        if(x<k&&y<k){
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    rep(i,k){
        if(!used[i]){
            c[i]=1;
            dfs(i,-1);
        }
    }
    int res=0;
    rep(i,k)res+=c[i];
    vector<int> b;
    rep(i,k){
        if(res>=0 && c[i]==1)b.push_back(i+1);
        if(res<0 && c[i]==-1)b.push_back(i+1);
    }
    cout<<1<<endl;
    rep(i,(k+1)/2){
        cout<<b[i]<<" ";
    }
    return 0;
}