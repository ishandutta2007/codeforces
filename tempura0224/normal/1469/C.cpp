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
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int l = 0, r = inf;
        bool ok=true;
        rep(i,n){
            int x;
            cin>>x;
            int nl = x, nr = x+k;
            if(i+1==n||i==0)nr = x+1;
            if(nr<=l||r<=nl)ok=false;
            l = max(l, nl), r = min(r, nr);
            r += k-1;
            l -= k-1;
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}