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
const ll mod=998244353 ;

int main(){
    int n;
    cin>>n;
    set<int> st;
    rep(i,n)st.insert(i);
    map<int,int> mp;
    rep(i,n){
        int x;cin>>x;
        if(mp[x]!=0){
            auto itr=st.lower_bound(mp[x]-1);
            while(*itr<i)itr=st.erase(itr);
        }
        else mp[x]=i+1;
    } 
    n=st.size();
    ll ret=1;
    rep(i,n-1)ret=ret*2%mod;
    cout<<ret<<endl;
    return 0;
}