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
    int n;
    cin>>n;
    vector<int> a(n);
    int m = -1;
    rep(i,n){
        cin>>a[i];
        if(a[i]==n)m=i;
    }
    bool ok=true;
    rep(i,m-1)if(a[i]>a[i+1])ok=false;
    REP(i,m+1,n-1)if(a[i]<a[i+1])ok=false;
    cout<<(ok?"YES":"NO")<<endl;
    return 0;
}