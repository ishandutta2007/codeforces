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
    string s;cin>>s;
    string t;
    cin>>t;
    int n=s.size(), m = t.size();
    vector<int> a(n+1), b(n+1);
    int idx = 0;
    rep(i,n){
        if(idx<m&&s[i]==t[idx]){
            ++idx;
            a[i+1]=idx;
        }
        else a[i+1]=a[i];
    }
    idx = 0;
    for(int i = n-1 ; i>=0;--i){
        if(idx<m&&s[i]==t[m-1-idx]){
            ++idx;
            b[i]=idx;
        }
        else b[i]=b[i+1];
    }
    int ans = 0;
    rep(i,n+1){
        int idx = lower_bound(a.begin(), a.end(), m-b[i])-a.begin();
        ans = max(ans,i-idx);
    }
    cout<<ans<<endl;
    return 0;
}