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
    string s[n];
    rep(i,n)cin>>s[i];
    vector<ll> posi(303030), nega(303030);
    rep(i,n){
        int c = 0;
        int mi=0;
        rep(j,s[i].size()){
            if(s[i][j]=='(')++c;
            else mi=min(--c,mi);
        }
        if(c>=0&&mi>=0)posi[c]++;
        if(c<0&&mi==c)nega[-c]++;
    }
    ll ans = posi[0]*posi[0];
    rep(i,303030)ans+=posi[i]*nega[i];
    cout<<ans<<endl;
    return 0;
}