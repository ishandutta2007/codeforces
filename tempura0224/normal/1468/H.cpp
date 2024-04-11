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

bool solve(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int> a(n,1);
    rep(i,m){
        int x;cin>>x;
        --x;
        a[x]=0;
    }
    vector<int> ok1(n), ok2(n);
    int l=0;
    rep(i,n){
        l+=a[i];
        if(a[i]==0&&l>=(k-1)/2)ok1[i]=1;
    }
    int r=0;
    for(int i=n-1;i>=0;--i){
        r+=a[i];
        if(a[i]==0&&r>=(k-1)/2)ok2[i]=1;
    }
    if(r%(k-1))return false;
    rep(i,n){
        if(ok1[i]&&ok2[i])return true;
    }
    return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cout<<(solve() ? "YES" : "NO") << endl;
    }
    return 0;
}