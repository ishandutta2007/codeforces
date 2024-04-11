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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> used(n);
    rep(i,m){
        int x;cin>>x;
        used[x]=1;
    }
    if(used[0]){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> pre(n, -1);
    rep(i,n){
        if(!used[i])pre[i]=i;
        else pre[i]=pre[i-1];
    }
    ll ans = longinf;
    for(int i=1;i<=k;i++){
        int t = 0;
        int p = -1;
        int cnt = 0;
        while(t<n){
            int nxt = pre[t];
            if(nxt == p){
                cnt = -1;
                break;
            } else {
                ++cnt;
                p=nxt;
                t=nxt+i;
            }
        }
        ll c;
        cin>>c;
        if(cnt>=0){
            ans = min(ans,c*cnt);
        }
    }
    if(ans == longinf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}