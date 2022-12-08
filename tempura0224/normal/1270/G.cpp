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


void solve(){
    int n;
    cin>>n;
    vector<int> nxt(n+1);
    rep(i,n){
        int x;
        cin>>x;
        nxt[i+1] = i+1-x;
    }
    vector<int> used(n+1);
    vector<int>ans;
    int cur= 1;
    while(1){
        if(used[cur]){
            ans.push_back(cur);
            int st = cur;
            while(nxt[cur]!=st){
                cur = nxt[cur];
                ans.push_back(cur);
            }
            break;
        }
        used[cur]=1;
        cur = nxt[cur];
    }
    cout<<ans.size()<<"\n";
    for(auto e:ans)cout<<e<<" ";
    cout<<"\n";
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    rep(i,t)solve();
    return 0;
}