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
    int n,m;
    cin>>n>>m;
    string a[n];
    rep(i,n)cin>>a[i];
    string b[m];
    rep(i,m)cin>>b[i];
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        --t;
        int y = t%m;
        int x = t%n;
        cout<<a[x]<<b[y]<<endl;
    }
    return 0;
}