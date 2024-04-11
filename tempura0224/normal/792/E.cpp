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
    vector<int> st;
    ll a[n];
    rep(_,1){
        ll x;
        cin>>x;
        a[0]=x;
        for(int i = 1 ; i*i<=x;++i){
            st.push_back(i);
            st.push_back(i+1);
            st.push_back(x/i);
            st.push_back(x/i+1);
            if(x/i>1)st.push_back(x/i-1);
        }
        sort(st.begin(),st.end());
        st.erase(unique(st.begin(),st.end()),st.end());
    }
    rep(i,n-1)cin>>a[i+1];
    int m = st.size();
    vector<ll> cnt(m),ans(m);
    rep(i,n){
        rep(j,m){
            ll cur = a[i]%(st[j]+1);
            if(cur==0){
                ++cnt[j];
                ans[j]+=a[i]/(st[j]+1);
            }
            else if(a[i]/(st[j]+1) >= st[j]-cur){
                ++cnt[j];
                ans[j]+=a[i]/(st[j]+1)+1;
            }
        }
    }
    ll mi = longinf;
    rep(j,m){
        if(cnt[j]==n)mi=min(mi,ans[j]);
    }
    cout<<mi<<endl;
    return 0;
}