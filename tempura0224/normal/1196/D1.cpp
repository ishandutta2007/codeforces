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
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> r(n+1), g(n+1), b(n+1);
        rep(i,n){
            if(i%3==0){
                if(s[i]!='R')++r[i+1];
                if(s[i]!='G')++g[i+1];
                if(s[i]!='B')++b[i+1];
            }
            else if(i%3==1){
                if(s[i]!='G')++r[i+1];
                if(s[i]!='B')++g[i+1];
                if(s[i]!='R')++b[i+1];
            }
            else if(i%3==2){
                if(s[i]!='B')++r[i+1];
                if(s[i]!='R')++g[i+1];
                if(s[i]!='G')++b[i+1];
            }
        }
        rep(i,n){
            r[i+1]+=r[i];
            g[i+1]+=g[i];
            b[i+1]+=b[i];
        }
        int ans = inf;
        rep(i,n-k+1){
            ans = min(ans,r[i+k]-r[i]);
            ans = min(ans,g[i+k]-g[i]);
            ans = min(ans,b[i+k]-b[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}