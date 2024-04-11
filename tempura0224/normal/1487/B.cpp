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
        int n,k;
        cin>>n>>k;
        //int a = n-1,b = n-2;
        //rep(i,k){
        //    //--a;if(a<0)a=n-1;
        //    b+=2;
        //    if(b>=n)b-=n;
        //    if(a==b){
        //        ++b;
        //        if(b==n)b=0;
        //    }
        //    cout<<b<<" "<<((b-i)%n+n)%n+1<<endl;;
        //}
        //cout<<endl;
        //cout<<(b%n+n)%n+1<<endl;
        int p = (n/2);
        int ret = 2 * ((k-1)%p);
        cout<<((ret-k+1)%n+n)%n+1<<endl;
    }
    return 0;
}