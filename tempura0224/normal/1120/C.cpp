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
const int MS = 2;
const long long mod[] = {999999937LL, 1000000007LL}, base = 9973;
struct rolling_hash {
    int n;
    vector<long long> hs[MS], pw[MS];
    rolling_hash(){}
    rolling_hash(const string &s) {
        n = s.size();
        for (int i = 0; i < MS; i++) {
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pw[i][j+1] = pw[i][j]*base%mod[i];
                hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
            }
        }
    }

    long long hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%mod[i]+mod[i])%mod[i]; }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l1,r1,i)==hash(l2,r2,i);
        return ret;
    }

    bool match(int l, int r, long long h[]) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l,r,i)==h[i];
        return ret;
    }
};

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    rolling_hash rh(s);
    vector<ll> dp(5050,longinf);
    dp[0]=0;
    int en = 0;
    rep(i,n){
        while(1){
            if(en==n)break;
            bool ok=false;
            int len = en+1-i;
            for(int j=0;j+len<=i;j++){
                if(rh.match(j,j+len,i,i+len)){
                    ok=true;
                    break;
                }
            }
            if(!ok)break;
            ++en;
        }
        dp[en]=min(dp[en],dp[i]+b);
        dp[i+1]=min(dp[i+1],dp[i]+a);
    }
    cout<<dp[n]<<endl;
    return 0;
}