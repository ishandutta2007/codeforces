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

ll n,m,d;
pll a[202020];
int idx[202020];
set<ll> st;
map<ll,int> mp;

void dfs(int x,int cnt){
    idx[mp[x]]=cnt;
    ll ret=*st.lower_bound(x+d);
    if(ret==longinf)return;
    st.erase(ret);
    dfs(ret,cnt);
}
int main(){
    cin>>n>>m>>d;
    ++d;
    rep(i,n){
        cin>>a[i].first;
        a[i].second=i;
        st.insert(a[i].first);
    }
    st.insert(longinf);
    sort(a,a+n);
    rep(i,n)mp[a[i].first]=a[i].second;
    int cnt=1;
    rep(i,n){
        if(idx[a[i].second]==0)dfs(a[i].first,cnt++);
    }
    cout<<cnt-1<<endl;
    rep(i,n)cout<<idx[i]<<" ";
    cout<<endl;
    return 0;
}