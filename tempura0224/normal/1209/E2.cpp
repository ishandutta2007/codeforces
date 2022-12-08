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
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> ma(m);
        vector<vector<int>> a(n,vector<int>(m));
        rep(i,n){
            rep(j,m){
                cin>>a[i][j];
                ma[j]=max(ma[j],a[i][j]);
            }
        }
        vector<int> ord(m);
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](int p,int q){
            return ma[p]>ma[q];
        });
        if(ord.size()>12)ord.resize(12);
        m = ord.size();
        vector<int> dp(1<<n,-inf);
        dp[0]=0;
        for(auto idx : ord){
            vector<int> ndp(1<<n,-inf);
            vector<int> memo(1<<n,-inf);
            rep(i,n){
                rep(mask,1<<n){
                    int res = 0;
                    rep(j,n){
                        if(mask&(1<<j)){
                            res += a[(i+j)%n][idx];
                        }
                    }
                    memo[mask]=max(memo[mask],res);
                }
            }
            rep(mask,1<<n){
                for(int i=mask; i>=0; i--) {
		        	i&=mask;
                    ndp[mask]=max(ndp[mask],memo[i]+dp[mask^i]);
		        }
            }
            dp.swap(ndp);
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}