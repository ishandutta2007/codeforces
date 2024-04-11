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
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n){
        rep(j,m)cin>>a[i][j];
        rep(j,m)--a[i][j];
    }
    int ans=0;
    rep(j,m){
        vector<int> cnt(n);
        rep(i,n){
            if(a[i][j]>=n*m)continue;
            if(a[i][j]%m==j){
                int tar = a[i][j]/m, cur = i;
                if(tar<=cur)cnt[cur-tar]++;
                else cnt[cur-tar+n]++;
            }
        }
        int ret = n;
        rep(i,n)ret = min(ret,n-cnt[i]+i);
        ans += ret;
    }
    cout<<ans<<endl;
    return 0;
}