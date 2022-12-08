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

ll table(ll n,ll t, ll k){
    if(t==0)return 0;
    ll num = 1ll<<(2*t);
    num/=4;
    if(n<num)return table(n,t-1,k);
    if(n<2*num){
        n-=num;
        if(k%3==0)return 1*num+table(n,t-1,k);
        if(k%3==1)return 2*num+table(n,t-1,k);
        if(k%3==2)return 3*num+table(n,t-1,k);
    }
    if(n<3*num){
        n-=2*num;
        if(k%3==0)return 2*num+table(n,t-1,k);
        if(k%3==1)return 3*num+table(n,t-1,k);
        if(k%3==2)return 1*num+table(n,t-1,k);
    }
    if(n<4*num){
        n-=3*num;
        if(k%3==0)return 3*num+table(n,t-1,k);
        if(k%3==1)return 1*num+table(n,t-1,k);
        if(k%3==2)return 2*num+table(n,t-1,k);
    }
    return -1;
}
ll solve(ll n){
    ll d = 0;
    while((1ll<<(2*d))<=n)++d;
    d--;
    n-=1ll<<(2*d);
    if(n%3==0)return table(n/3,d,n%3)+(1ll<<(2*d));
    else if(n%3==1) return table(n/3,d,n%3)+(2ll<<(2*d));
    else return table(n/3,d,n%3)+(3ll<<(2*d));
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}