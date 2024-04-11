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
    vector<pair<ll,int>> v;
    ll b[n];
    rep(i,n){
        ll x,y;
        cin>>x>>b[i];
        b[i]=3*b[i]+1;
        v.emplace_back(3*x+1,i);
    }
    int m;
    cin>>m;
    ll d[m],cnt[m];
    rep(i,m){
        ll x,y;
        cin>>x>>y>>cnt[i];
        v.emplace_back(3*x,i);
        v.emplace_back(3*y+2,i);
        d[i]=3*y+2;
    }
    sort(v.begin(),v.end());
    set<pair<ll,int>> st;
    vector<int> ans(n);
    for(auto p : v){
        if(p.first%3==0){
            st.emplace(d[p.second],p.second);
        }
        else if(p.first%3==1){
            auto itr=st.lower_bound({b[p.second],0});
            if(itr==st.end()){
                cout<<"NO"<<endl;
                return 0;
            }
            ans[p.second]=itr->second;
            if(--cnt[itr->second]==0)itr=st.erase(itr);
        }
        else {
            auto itr=st.lower_bound(p);
            if(*itr==p)itr=st.erase(itr);
        }
    }
    cout<<"YES"<<endl;
    rep(i,n){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}