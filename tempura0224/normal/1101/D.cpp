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

map<int,int> mp[202020];

vector<int> v[202020];
int a[202020],ans;

void dfs(int x,int p){
    for(int i=2;i<500;++i){
        if(a[x]==1)break;
        if(a[x]%i==0){
            mp[x][i]=1;
            while(a[x]%i==0){
                a[x]/=i;
            }
        }
    }
    if(a[x]!=1)mp[x][a[x]]=1;

    for(auto to:v[x]){
        if(to==p)continue;
        dfs(to,x);
        for(auto& e:mp[x]){
            int res=mp[to][e.first];
            ans=max(res+e.second,ans);
            if(res>=e.second)e.second=res+1;
        }
    }
}

int main(){
    int n;
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0,-1);
    cout<<ans<<endl;
    return 0;
}