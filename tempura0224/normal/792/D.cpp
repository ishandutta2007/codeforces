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

ll n;
ll up(ll x){
    ll st = 2;
    while(x%st==0)st*=2;
    ll l = x-st/2, r = x+st/2;
    if(l%(2*st)==0){
        if(r>n)return x;
        else return r;
    }
    else {
        if(l>n)return x;
        return l;
    }
}
ll left(ll x){
    if(x%2)return x;
    ll st = 2;
    while(x%st==0)st*=2;
    return x-st/4;
}
ll right(ll x){
    if(x%2)return x;
    ll st = 2;
    while(x%st==0)st*=2;
    return x+st/4;
}

int main(){
    cin>>n;
    int q;
    cin>>q;
    while(q--){
        ll u;scanf("%lld",&u);
        string s;
        cin>>s;
        rep(i,s.size()){
            if(s[i]=='U')u=up(u);
            if(s[i]=='L')u=left(u);
            if(s[i]=='R')u=right(u);
        }
        printf("%lld\n",u);
    }
    return 0;
}