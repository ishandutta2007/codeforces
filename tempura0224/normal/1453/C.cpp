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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s[n];
        rep(i,n)cin>>s[i];
        for(char c='0';c<='9';c++){
            int mi = n, ma = -1;
            int cnt=0;
            rep(i,n){
                rep(j,n)if(s[i][j]==c){
                    ++cnt;
                    mi=min(i,mi);ma=max(i,ma);
                }
            }
            if(cnt<2){
                cout<<0<<" ";
                continue;
            }
            int ans = 0;
            rep(i,n){
                int l=n, r=-1;
                rep(j,n)if(s[i][j]==c){
                    l=min(l,j);r=max(r,j);
                }
                if(l==n)continue;
                ans = max(ans,max((i-mi),(ma-i))*max(r, n-1-l));
                ans = max(ans,max(i, (n-1-i))*(r-l));
            }

            mi = n, ma=-1;
            rep(i,n){
                rep(j,n)if(s[i][j]==c){
                    ++cnt;
                    mi=min(j,mi);ma=max(j,ma);
                }
            }
            rep(j,n){
                int u=n, d=-1;
                rep(i,n)if(s[i][j]==c){
                    u=min(u,i);d=max(d,i);
                }
                if(u==n)continue;
                ans = max(ans,max((j-mi),(ma-j))*max(d, n-1-u));
                ans = max(ans,max(j, (n-1-j))*(d-u));
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}