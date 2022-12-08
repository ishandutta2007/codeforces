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
    ll n,m,k;
    cin>>n>>m>>k;
    ll p[m];
    rep(i,m)cin>>p[i];
    rep(i,m)--p[i];
    int ans = 0;
    ll rem = 0;
    int idx = 0;
    while(1){
        if(idx==m)break;
        ll cur = (p[idx]+rem)/k;
        while(idx<m&&(p[idx]+rem)/k==cur)++idx;
        ++ans;
        rem = (k-idx%k)%k;
    }
    cout<<ans<<endl;
    return 0;
}