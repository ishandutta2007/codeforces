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
    vector<int> d(n);
    rep(i,n)cin>>d[i];
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return d[x]>d[y];
    });
    set<pair<int,int>> st;
    vector<pair<int,int>> ans;
    st.emplace(0,2*ord[0]);
    rep(i,n-1){
        ans.emplace_back(2*ord[i],2*ord[i+1]);
        st.emplace(i+1,2*ord[i+1]);
    }
    int ma = n-1;
    rep(i,n){
        int x = d[ord[i]]+i;
        auto itr = st.lower_bound({x-1,-1});
        ans.emplace_back(itr->second,2*ord[i]+1);
        if(x>ma){
            st.emplace(x,2*ord[i]+1);
            ma=x;
        }
    }
    for(auto p : ans){
        cout<<p.first+1<<" "<<p.second+1<<"\n";
    }
}