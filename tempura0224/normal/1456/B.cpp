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
    int n;
    cin>>n;
    if(n>=100){
        cout<<1<<endl;
        return 0;
    }
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int ans = inf;
    rep(m,n-1){
        vector<int> l, r;
        ll cur = 0;
        for(int i=m-1;i>=0;i--){
            cur^=a[i];
            l.push_back(cur);
        }
        cur = 0;
        for(int i=m;i<n;i++){
            cur^=a[i];
            r.push_back(cur);
        }
        rep(i,l.size())rep(j,r.size()){
            if(l[i]>r[j])ans=min(ans,i+j);
        }
    }
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}