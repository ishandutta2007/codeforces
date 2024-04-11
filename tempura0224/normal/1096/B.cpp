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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt1=0,cnt2=0;
    while(s[cnt1]==s[0])++cnt1;
    while(s[n-cnt2-1]==s[n-1])++cnt2;
    if(s[0]!=s[n-1]){
        cout<<cnt1+cnt2+1<<endl;
    }
    else cout<<(cnt1+1)*(cnt2+1)%mod<<endl;
    return 0;
}