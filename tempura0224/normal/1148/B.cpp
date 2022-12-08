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
    ll ta,tb,k;
    cin>>ta>>tb>>k;
    ll a[n],b[m+1];
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    b[m]=inf;
    vector<int> dp(m+1);
    dp[0]=0;
    rep(i,m){
        int num=upper_bound(a,a+n,b[i]-ta)-a;
        dp[i+1]=min(dp[i]+1,num);
    }
    for(int i=m;i>=0;--i){
        if(dp[i]<=k){
            if(i==m)cout<<-1<<endl;
            else cout<<b[i]+tb<<endl;
            return 0;
        }
    } 
    return 0;
}