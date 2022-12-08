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

int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    int B = 62;
    vector<int> v[n+B];
    rep(i,n){
        rep(j,B)if((1ll<<j)&a[i]){
            v[i].push_back(n+j);
            v[n+j].push_back(i);
        }
    }
    rep(j,B){
        if(v[n+j].size()>=3){
            cout<<3<<endl;
            return 0;
        }
    }
    int dist[2*B][2*B];
    rep(i,2*B)rep(j,2*B)dist[i][j]=inf;
    rep(i,2*B)dist[i][i]=0;
    map<int,int> mp;
    int idx = 0;
    rep(i,B){
        if(v[n+i].size()<=1)continue;
        int x = v[n+i][0], y = v[n+i][1];
        if(!mp.count(x))mp[x]=idx++;
        if(!mp.count(y))mp[y]=idx++;
        dist[mp[x]][mp[y]]=dist[mp[y]][mp[x]]=1;
    }
    int ans = inf;
    rep(i,2*B)rep(j,i){
        if(dist[i][j]==inf)continue;
        int nd[2*B][2*B];
        rep(k,2*B)rep(l,2*B){
            nd[k][l]=dist[k][l];
        }
        nd[i][j]=nd[j][i]=inf;
        rep(k,2*B)rep(l,2*B)rep(m,2*B){
            nd[l][m]=min(nd[l][m],nd[l][k]+nd[k][m]);
        }
        ans = min(ans,nd[i][j]+1);
    }
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}