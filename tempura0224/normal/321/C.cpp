#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int used[101010],sz[101010],ran[101010];
vector<int> v[101010];

int szdfs(int x,int p=-1){
    sz[x]=1;
    for(auto to:v[x]){
        if(used[to]||to==p)continue;
        sz[x]+=szdfs(to,x);
    }
    return sz[x];
}

int centroid(int x,int p,int total){
    for(auto to:v[x]){
        if(used[to]||to==p)continue;
        if(2*sz[to]>total)return centroid(to,x,total);
    }
    return x;
}

void build(int x,int p=-1){
    szdfs(x);
    x=centroid(x,-1,sz[x]);
    ran[x]=(p==-1?0:ran[p]+1);
    used[x]=true;
    for(auto to:v[x]){
        if(used[to]||to==p)continue;
        build(to,x);
    }
}

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    build(0);
    rep(i,n)printf("%c ",ran[i]+'A');
    cout<<endl;
}