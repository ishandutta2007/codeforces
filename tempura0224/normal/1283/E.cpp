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
    rep(i,n)cin>>a[i];
    vector<int> used(n+2);
    sort(a.begin(),a.end());
    rep(i,n){
        if(used[a[i]-1]||used[a[i]])continue;
        used[a[i]+1]=1;
    }
    int ans = 0;
    rep(i,n+2)ans+=used[i];
    cout<<ans<<" ";
    rep(i,n+2)used[i]=0;
    rep(i,n){
        if(!used[a[i]-1])used[a[i]-1]=1;
        else if(!used[a[i]])used[a[i]]=1;
        else used[a[i]+1]=1;
    }
    ans=0;
    rep(i,n+2)ans+=used[i];
    cout<<ans<<endl;
    return 0;
}