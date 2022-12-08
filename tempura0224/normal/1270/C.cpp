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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll s=0,x=0;
        rep(i,n){
            int a;cin>>a;
            s+=a;x^=a;
        }
        ll e = 1e16;
        if(s%2==1)e+=1;
        s+=e;x^=e;
        ll res = 2*x-s;
        cout<<3<<endl;
        cout<<e<<" "<<res/2<<" "<<res/2<<endl;
        //assert(e>0 && res>=0);
        //assert(s+res/2+res/2==2*x);
    }
    return 0;
}