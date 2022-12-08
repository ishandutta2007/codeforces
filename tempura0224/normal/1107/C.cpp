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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<ll> que;
    ll a[n];
    rep(i,n)cin>>a[i];
    string s;
    cin>>s;
    char pre='-';
    ll ans=0;
    rep(i,n){
        if(s[i]==pre)que.push(a[i]);
        else {
            int m = min(k,(int)que.size());
            rep(i,m){
                ans+=que.top();
                que.pop();
            }
            while(!que.empty())que.pop();
            que.push(a[i]);
            pre = s[i];
        }
    }
    int m = min(k,(int)que.size());
    rep(i,m){
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
    return 0;
}