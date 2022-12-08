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


int dp[300][3];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt1=0,cnt2=0;
        int ans = 0;
        rep(i,n){
            int x;
            cin>>x;
            if(x%3==0)++ans;
            if(x%3==1)++cnt1;
            if(x%3==2)++cnt2;
        }
        ans+=min(cnt1,cnt2);
        ans+=abs(cnt1-cnt2)/3;
        cout<<ans<<endl;

    }
    return 0;
}