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
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<ll> ans(128);
        vector<int> a(m);
        rep(i,m)cin>>a[i];
        vector<int> b(n);
        b[n-1]++;
        rep(i,m)b[a[i]-1]++;
        rep(i,n-1)b[n-i-2]+=b[n-i-1];
        rep(i,n)ans[s[i]]+=b[i];
        REP(i,'a','z'+1){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}