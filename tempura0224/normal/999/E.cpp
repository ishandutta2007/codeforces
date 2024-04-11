#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
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
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

int n,used[5050],cmp[5050],ok[5050];
vector<int> v[5050],rv[5050],vs;

void dfs(int x){
    used[x]=true;
    rep(i,v[x].size())if(!used[v[x][i]])dfs(v[x][i]);
    vs.push_back(x);
}

void rdfs(int x,int k){
    used[x]=true;
    cmp[x]=k;
    rep(i,rv[x].size())if(!used[rv[x][i]])rdfs(rv[x][i],k);
}

int scc(){
    rep(i,n)if(!used[i])dfs(i);
    rep(i,n)used[i]=0;
    int k=0;
    int t=vs.size();
    rep(i,t)if(!used[vs[t-i-1]])rdfs(vs[t-i-1],k++);
    return k;
}

void check(int x){
    used[x]=true;
    ok[cmp[x]]=true;
    rep(i,v[x].size())if(!used[v[x][i]])check(v[x][i]);
}
int main(){
    cin>>n;
    int m;
    cin>>m;
    int s;cin>>s;
    s--;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        rv[y].push_back(x);
    }
    int c=scc();
    rep(i,n)used[i]=false;
    ok[cmp[s]]=true;
    rep(i,n){
        if(ok[cmp[i]])continue;
        rep(j,rv[i].size()){
            if(cmp[i]!=cmp[rv[i][j]])ok[cmp[i]]=true;
        }
    }
    int ans=0;
    rep(i,c)if(!ok[i])ans++;
    cout<<ans<<endl;
    return 0;
}