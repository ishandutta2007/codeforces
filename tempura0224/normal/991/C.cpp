#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
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
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

ll calc(ll n,ll k){
    ll cnt=0;
    while(n>k){
        n-=k;
        n-=n/10;
        cnt++;
    }
    return cnt*k+n;
}
int main(){
    ll x;cin>>x;
    ll ok=1e18,ng=0,mid;
    while(ok-ng>1){
        mid=(ok+ng)/2;
        if(2*calc(x,mid)>=x)ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
    return 0;
}