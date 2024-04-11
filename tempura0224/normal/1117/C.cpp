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
const ll longinf=1e15 ;
const ll mod=1e9+7 ;

int main(){
    ll x,y;
    cin>>x>>y;
    int a;cin>>a;
    x=a-x;
    cin>>a;
    y=a-y;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ng=0,ok=longinf;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        ll mx=0,my=0;
        ll cnt=mid/n;
        rep(i,n){
            if(s[i]=='U')my+=cnt;
            if(s[i]=='D')my-=cnt;
            if(s[i]=='R')mx+=cnt;
            if(s[i]=='L')mx-=cnt;
        }
        rep(i,(mid%n)){
            if(s[i]=='U')my++;
            if(s[i]=='D')my--;
            if(s[i]=='R')mx++;
            if(s[i]=='L')mx--;
        }
        ll dist=abs(mx-x)+abs(my-y);
        if(dist<=mid)ok=mid;
        else ng=mid;
    }
    if(ok==longinf){
        cout<<-1<<endl;
    }
    else cout<<ok<<endl;

    return 0;
}