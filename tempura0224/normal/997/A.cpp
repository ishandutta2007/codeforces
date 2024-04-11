#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
    int n;
    cin>>n;
    ll x,y;
    cin>>x>>y;
    string s;
    cin>>s;
    char pos='1';
    int cnt=0;
    rep(i,n){
        if(pos=='1'&&s[i]=='0')cnt++;
        pos=s[i];
    }
    ll ans=(cnt-1)*min(x,y)+y;
    if(cnt==0)ans=0;
    cout<<ans<<endl;
    return 0;
}