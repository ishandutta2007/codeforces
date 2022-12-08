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


int dp[6];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int ans = 0;
    rep(i,n){
        if(a[i]==4)++dp[0];
        if(a[i]==8){
            if(dp[0]){
                ++dp[1];
                --dp[0];
            }
            else ++ans;
        }
        if(a[i]==15){
            if(dp[1]){
                ++dp[2];
                --dp[1];
            }
            else ++ans;
        }
        if(a[i]==16){
            if(dp[2]){
                ++dp[3];
                --dp[2];
            }
            else ++ans;
        }
        if(a[i]==23){
            if(dp[3]){
                ++dp[4];
                --dp[3];
            }
            else ++ans;
        }
        if(a[i]==42){
            if(dp[4]){
                ++dp[5];
                --dp[4];
            }
            else ++ans;
        }
    }
    rep(i,5)ans += (i+1)*dp[i];
    cout<<ans<<endl;
    return 0;
}