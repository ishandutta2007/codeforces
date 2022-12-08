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
    int h,w;
    cin>>h>>w;
    string s[h];
    rep(i,h)cin>>s[i];
    ll ans = 0;
    int mi, ma;
    for(int i = 1 ; i < h-1 ; ++i){
        int cnt = 0;
        rep(j,w){
            if(s[i][j]==s[i-1][j]){
                cnt = 0;
                continue;
            }
            if(cnt!=0){
                bool ok=true;
                REP(k,mi,ma)if(s[k][j]!=s[k][j-1])ok=false;
                if(ok){
                    ++cnt;
                    ans += cnt;
                }
                else cnt = 0;
            }
            if(cnt == 0){
                int k = i;
                while(k<h&&s[i][j]==s[k][j])++k;
                int sz = k-i;
                mi = i-1, ma = k;
                while(i-mi<=sz&&mi>=0&&s[mi][j]==s[i-1][j])--mi;
                ++mi;
                while(ma-k<sz&&ma<h&&s[ma][j]==s[k][j])++ma;
                if(ma-k!=sz||i-mi!=sz)continue;
                else ++cnt;
                ans += 1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}