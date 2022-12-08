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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> v[101010];
int dist[101010],dist2[101010];
int a[101010];

void dfs1(int x,int p){
    for(auto to:v[x]){
        if(to==p)continue;
        dist[to]=dist[x]+1;
        dfs1(to,x);
    }
}

void dfs2(int x,int p){
    for(auto to:v[x]){
        if(to==p)continue;
        dist[to]=dist[x]-1;
        dfs2(to,x);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(0,-1);
    int pos=0;
    rep(i,n){
        if(dist[i]>dist[pos])pos=i;
    }
    dist[pos]=0;
    dfs1(pos,-1);
    rep(i,n)dist2[i]=dist[i];
    pos=0;
    rep(i,n)if(dist[i]>dist[pos])pos=i;
    int ma=dist[pos];
    dist[pos]=0;
    dfs1(pos,-1);
    bool ok=true;
    if(ma%2)ok=false;
    ma/=2;
    int res=0;
    rep(i,n)if(dist[i]==ma&&dist2[i]==ma)res=i;
    dist[res]=k;
    dfs2(res,-1);
    rep(i,n){
        if(dist[i]==k){
            if(v[i].size()<3)ok=false;
        }
        else if(dist[i]<0)ok=false;
        else if(dist[i]==0){
            if(v[i].size()!=1)ok=false;
        }
        else {
            if(v[i].size()<4)ok=false;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}