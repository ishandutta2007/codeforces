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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> v[302020];
int cnt[2][302020],a[302020];

void dfs(int x,int p){
    for(auto to :v[x]){
        if(to==p)continue;
        dfs(to,x);
        rep(i,2)cnt[i][x]+=cnt[i][to];
    }
    if(a[x]==1)cnt[0][x]++;
    if(a[x]==2)cnt[1][x]++;
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
    int ans=0;
    rep(i,n-1){
        if(cnt[0][i+1]==cnt[0][0]&&cnt[1][i+1]==0)++ans;
        else if(cnt[1][i+1]==cnt[1][0]&&cnt[0][i+1]==0)++ans;
    }
    cout<<ans<<endl;

    return 0;
}