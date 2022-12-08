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

ll solve(vector<ll> a,int b){
    if(b==-1)return 0;
    ll bo = 1ll<<b;
    vector<ll> l, r;
    for(auto e:a){
        if(e<bo)l.push_back(e);
        else r.push_back(e-bo);
    }
    if(l.empty())return solve(r,b-1);
    if(r.empty())return solve(l,b-1);
    return min(solve(l,b-1),solve(r,b-1))+bo;
}


int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    cout<<solve(a,32)<<endl;
    return 0;
}