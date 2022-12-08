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
        int n;cin>>n;
        vector<int> a(n+1),b(n+1);
        rep(i,n)cin>>a[i+1]>>b[i+1];
        bool ok=true;
        rep(i,n){
            if(a[i+1]-a[i]<b[i+1]-b[i])ok=false;
            if(a[i+1]-a[i]<0)ok=false;
            if(b[i+1]-b[i]<0)ok=false;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}