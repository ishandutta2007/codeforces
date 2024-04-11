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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        rep(i,n)cin>>a[i];
        rep(i,n)cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        rep(i,n)cout<<a[i]<<" \n"[i+1==n];
        rep(i,n)cout<<b[i]<<" \n"[i+1==n];
    }   
    return 0;
}