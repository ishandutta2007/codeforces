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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = n*(n-1)/2;
    int i = 0;
    while(i<n && s[i]==s[0])++i;
    int j = 0;
    while(j<n && s[n-1-j]==s[n-1])++j;
    rep(k,n-1)if(s[k]!=s[k+1])++ans;
    cout<<ans-(n-i)-(n-j)<<endl;
    return 0;
}