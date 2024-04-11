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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


ll dp[1010101];

int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    dp[0]=1;
    rep(i,n){
        vector<int> v;
        for(int j=1;j*j<=a[i];++j){
            if(a[i]%j==0){
                if(j*j!=a[i])v.push_back(j);
                (dp[a[i]/j]+=dp[a[i]/j-1])%=mod;
            }
        }
        reverse(v.begin(),v.end());
        for(auto e:v)(dp[e]+=dp[e-1])%=mod;
    }
    ll sum=0;
    rep(i,n)sum+=dp[i+1];
    cout<<sum%mod<<endl;
    return 0;
}