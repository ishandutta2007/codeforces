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
const ll mod=1e9+7 ;

bool used[101010];

ll gcd(ll x,ll y){
    if(x<y)swap(x,y);
    return y==0? x : gcd(y,x%y);
}
int main(){
    ll n;
    cin>>n;
    vector<ll> ans;
    ans.push_back(1);
    REP(i,1,101010){
        ll res=gcd(n,i);
        if(used[res])continue;
        used[res]=true;
        ll cnt=n/res;
        ll ret=cnt*(cnt-1)/2;
        ans.push_back(ret*res+cnt);

        ret=res*(res-1)/2;
        ans.push_back(ret*cnt+res);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(auto e:ans)cout<<e<<" ";
    return 0;
}