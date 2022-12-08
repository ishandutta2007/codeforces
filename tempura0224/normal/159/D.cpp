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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    s = '-' + s + "$";
    vector<ll> beg(n+1),end(n+1);
    rep(i,n){
        int j =0;
        while(s[i+1+j]==s[i+1-j]){
            beg[i-j]++;
            end[i+j]++;
            ++j;
        }
        j = 0;
        while(s[i+1-j]==s[i+2+j]){
            beg[i-j]++;
            end[i+j+1]++;
            ++j;
        }
    }
    rep(i,n)end[i+1]+=end[i];
    ll ans=0;
    rep(i,n){
        ans+=end[i]*beg[i+1];
    }
    cout<<ans<<endl;
    return 0;
}