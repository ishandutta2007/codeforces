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

vector<int> v[202020];
ll s[202020];
ll a[202020];
void dfs(ll sum,int x){
    if(s[x]!=-1){
        a[x]=s[x]-sum;
        sum=s[x];
    }
    else {
        ll ret=inf;
        for(auto to:v[x]){
            ret=min(ret,s[to]-sum);
        }
        if(ret==inf)ret=0;
        a[x]=ret;
        sum+=a[x];
    }
    for(auto to:v[x]){
        dfs(sum,to);
    }
}

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int x;cin>>x;
        v[--x].push_back(i+1);
    }
    rep(i,n)cin>>s[i];
    dfs(0,0);
    ll ans=0;
    rep(i,n){
        if(a[i]<0){
            cout<<-1<<endl;
            return 0;
        }
        ans+=a[i];
    }
    cout<<ans<<endl;
    return 0;
}