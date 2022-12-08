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

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    return b?gcd(b,a%b) : a;
}

ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(){
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    if(a<b)swap(a,b);
    ll res=a-b;
    ll ret=a*b;
    ll ans=0;
    for(int i=1;i<=100000;++i){
        if(res%i==0){
            ll add=(i-a%i)%i;
            ll cur=lcm(a+add,b+add);
            if(cur<ret){
                ret=cur;
                ans=add;
            }
            else if(cur==ret){
                ans=min(add,ans);
            }
            ll nxt=res/i;
            add=(nxt-a%nxt)%nxt;
            cur=lcm(a+add,b+add);
            if(cur<ret){
                ret=cur;
                ans=add;
            }
            else if(cur==ret){
                ans=min(add,ans);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}