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
        string s;
        cin>>s;
        int i = 0, j = 0;
        string S="$";
        int n=s.size();
        rep(i,n){
            S+=s[i];
            S+='$';
        }
        vector<int> R(2*n+2);
        while (i < S.size()) {
          while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
          R[i] = j;
          int k = 1;
          while (i-k >= 0 && i+k < S.size() && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
          i += k; j -= k;
        }
        int ma = 0;
        while(ma<n&&s[ma]==s[n-ma-1])++ma;
        int ans = 0, idx = -1;
        REP(i,1,2*n){
            if(i<=n){
                int cur = R[i];
                if(i-cur<=2*ma){
                    if(i<=n && i>ans){
                        ans = i;
                        idx = i;
                    }
                }
            }
            else {
                int cur = R[i];
                if(2*n+1-(i+cur)<=2*ma){
                    if(2*n-i<=n&&2*n-i>ans){
                        ans = 2*n-i;
                        idx = i;
                    }
                }

            }
        }
        if(idx<n+1){
            string res = "";
            rep(j,idx){
                if(S[j]!='$')res += S[j];
            }
            string rres(res.rbegin(),res.rend());
            if(S[idx]!='$'){
                cout<<res<<S[idx]<<rres<<endl;
            }
            else cout<<res<<rres<<endl;
        }
        else {
            string res = "";
            REP(j,idx+1,2*n+1){
                if(S[j]!='$')res += S[j];
            }
            string rres(res.rbegin(),res.rend());
            if(S[idx]!='$'){
                cout<<rres<<S[idx]<<res<<endl;
            }
            else cout<<rres<<res<<endl;
        }
    }
    return 0;
}