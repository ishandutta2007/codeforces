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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int b[]={10,10,11,2,5,9,3,9,5,2,11};
ll dp[101010][11];

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> a(n);
    rep(i,n)a[i]=s[i]-'0';
    rep(i,n){
        rep(j,11){
            if(a[i]<j){
                dp[i+1][(b[j]+a[i])%11]+=dp[i][j];
            }
        }
        if(a[i]!=0)dp[i+1][a[i]]++;
    }
    ll ans=0;
    rep(i,n)rep(j,11)ans+=dp[i+1][j];
    cout<<ans<<endl;
    return 0;
}