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


struct q{ll x,y,z;};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        --x;--y;
        a[x]+=z;
        a[y]-=z;
    }
    ll idx=-1,ma=0;
    vector<pair<ll,int>> p(n);
    rep(i,n)p[i]={a[i],i+1};
    sort(p.begin(),p.end());
    int r=n-1;
    vector<q> ans;
    rep(i,n){
        if(p[i].first==0)break;
        while(p[i].first<0){
            if(p[r].first>=-p[i].first){
                ans.push_back({p[r].second,p[i].second,-p[i].first});
                p[r].first+=p[i].first;
                p[i].first=0;
            }
            else {
                if(p[r].first!=0)ans.push_back({p[r].second,p[i].second,p[r].first});
                p[i].first+=p[r].first;
                p[r].first=0;
                --r;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto e:ans){
        cout<<e.x<<" "<<e.y<<" "<<e.z<<endl;
    }
    return 0;
}