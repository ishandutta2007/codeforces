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
    int a[n];
    rep(i,n)cin>>a[i];
    int ans = inf;
    rep(i,n){
        bool ok=true;
        map<int,int> mp;
        rep(j,i)if(++mp[a[j]]==2)ok=false;
        if(!ok)break;
        ans = min(ans,n-i);
        for(int j = n-1;j>=0;--j){
            if(++mp[a[j]]==2)break;
            ans = min(ans,j-i);
        }
    }
    cout<<ans<<endl;

    return 0;
}