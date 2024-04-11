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
    int n;
    cin>>n;
    ll x;
    cin>>x;
    ll a[n-1];
    rep(i,n-1)cin>>a[i];
    vector<int> ord(n-1);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return a[x]>a[y];
    });
    ll sum = x;
    rep(i,n-1){
        sum+=a[i];
    }
    ll cur = x;
    vector<int> ans(1,1);
    for(auto i : ord){
        if(cur>sum-cur)break;
        if(2*a[i]>x)continue;
        ans.push_back(i+2);
        cur+=a[i];
    }
    if(cur<=sum-cur){
        cout<<0<<endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}