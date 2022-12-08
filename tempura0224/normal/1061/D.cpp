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
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;cin>>n;
    ll x,y;
    cin>>x>>y;
    pll p[n];
    rep(i,n)cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    multiset<ll> st;
    ll sum=0;
    st.insert(longinf);
    st.insert(-longinf);
    rep(i,n){
        auto itr=st.lower_bound(p[i].first);
        --itr;
        ll res=*itr;
        if(res!=-longinf&&x>y*(p[i].first-res)){
            st.erase(itr);
            sum+=(p[i].second-res)*y;
        }
        else sum+=x+(p[i].second-p[i].first)*y;
        sum%=mod;
        st.insert(p[i].second);
    }
    cout<<sum%mod<<endl;
    return 0;
}