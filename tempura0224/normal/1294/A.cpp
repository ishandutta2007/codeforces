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
        int a[3],n;
        cin>>a[0]>>a[1]>>a[2]>>n;
        sort(a,a+3);
        n -= a[2]-a[0];
        n -= a[2]-a[1];
        if(n<0)cout<<"NO"<<endl;
        else if(n%3==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}