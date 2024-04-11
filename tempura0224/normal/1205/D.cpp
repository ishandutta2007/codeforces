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

vector<int> v[1010];
vector<int> sz(1010), used(1010);

void szdfs(int x,int p){
    sz[x]=1;
    for(auto to : v[x]){
        if(to==p||used[to])continue;
        szdfs(to,x);
        sz[x]+=sz[to];
    }
}

int centroid(int x,int p,int total){
    for(auto to : v[x]){
        if(to==p||used[to])continue;
        if(2*sz[to]>total)return centroid(to,x,total);
    }
    return x;
}

vector<int> ans(1010);

void dfs(int x,int p,int& k,int diff){
    ans[x]=k;
    k+=diff;
    for(auto to:v[x]){
        if(to==p)continue;
        dfs(to,x,k,diff);
    }
}

int dp[1010][2020];
int main(){
    int n;
    cin>>n;
    if(n==2){
        cout<<"1 2 1"<<endl;
        return 0;
    }
    if(n==1)return 0;
    vector<pair<int,int>> p;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
        p.emplace_back(x,y);
    }
    szdfs(0,-1);
    int x = centroid(0,-1,sz[x]);
    szdfs(x,-1);
    int m = v[x].size();
    vector<int> a(m),b(m);
    rep(i,m){
        a[i]=v[x][i];
        b[i]=sz[v[x][i]];
    }
    dp[0][0]=1;
    rep(i,m)rep(j,n+1){
        dp[i+1][j]|=dp[i][j];
        dp[i+1][j+b[i]]|=dp[i][j];
    }
    int s = 0;
    while(3*(s+1)<n||dp[m][s]==0)++s;
    int t = s;
    vector<int> c(m);
    for(int i = m-1 ; i>=0;--i){
        if(t>=b[i]&&dp[i][t-b[i]]){
            t-=b[i];
            c[i]=1;
        }
    }
    int y=1, z=s+1;
    rep(i,m){
        if(c[i])dfs(v[x][i],x,y,1);
        else dfs(v[x][i],x,z,s+1);
    }
    for(auto e: p){
        cout<<e.first+1<<" "<<e.second+1<<" "<<abs(ans[e.first]-abs(ans[e.second]))<<"\n";
    }
    return 0;
}