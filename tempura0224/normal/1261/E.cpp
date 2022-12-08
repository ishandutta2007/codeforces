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

int used[1010];
int ans[1010][1010];
int h[1010];
int n;
int cur;
void solve(){
    int ma = 0;
    rep(i,n){
        if(!used[i])ma=max(h[i],ma);
    }
    if(ma==0)return;
    vector<int> ms;
    rep(i,n){
        if(!used[i]&&h[i]==ma)ms.push_back(i);
    }
    rep(j,ms.size()){
        rep(i,ma){
            ans[(cur-i-j+2*cur+1)%(cur+1)][ms[j]]=1;
        }
    }
    rep(i,ms.size())used[ms[i]]=1;
    cur = cur - ms.size();
    rep(i,n){
        if(!used[i] && h[i]>cur){
            rep(j,h[i]-cur)ans[j+cur+1][i]=1;
            h[i]=cur;
        }
    }
    solve();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n)cin>>h[i];
    cur=n;
    solve();
    cout<<n+1<<endl;
    rep(i,n+1){
        rep(j,n)cout<<ans[i][j];
        cout<<'\n';
    }
    return 0;
}