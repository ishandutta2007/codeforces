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
    int n,x;
    cin>>n>>x;
    vector<int> ok(2<<20,1);
    ok[0]=false;
    ok[x]=false;
    vector<int> ans;
    rep(i,1<<n){
        if(!ok[i])continue;
        ans.push_back(i);
        ok[x^i]=false;
        ok[i]=false;
    }
    int m=ans.size();
    rep(i,m-1){
        ans[m-i-1]^=ans[m-i-2];
    }
    cout<<m<<endl;
    for(auto e : ans){
        printf("%d ",e);
    }
    cout<<endl;
    return 0;
}