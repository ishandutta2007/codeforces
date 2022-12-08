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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


ll det(pair<ll,ll> x,pair<ll,ll> y){
    return x.first*y.second-x.second*y.first;
}
pair<ll,ll> sub(pair<ll,ll> x,pair<ll,ll> y){
    return make_pair(x.first-y.first, x.second-y.second);
}
int main(){
    int n;
    cin>>n;
    map<ll,ll> mp;
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        if(!mp.count(x))mp[x]=x*x-y;
        else mp[x]=min(mp[x],x*x-y);
    }
    vector<pair<ll,ll>> p;
    for(auto pp : mp){
        p.push_back(pp);
    }
    sort(p.begin(),p.end(),[](auto x,auto y){
        if(x.first!=y.first)return x.first<y.first;
        return x.second < y.second;
    });
    vector<pair<ll,ll>> res(2*n);
    int k=0;
    rep(i,p.size()){
        while(k>1&&det(sub(res[k-1],res[k-2]),sub(p[i],res[k-1]))<=0)--k;
        res[k++]=p[i];
    }
    cout<<k-1<<endl;
    return 0;
}