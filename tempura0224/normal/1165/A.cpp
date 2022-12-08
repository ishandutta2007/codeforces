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
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int ans=0;
    rep(i,x){
        if(i!=y&&s[i]=='1')++ans;
        if(i==y&&s[i]=='0')++ans;
    }
    cout<<ans<<endl;
    return 0;
}