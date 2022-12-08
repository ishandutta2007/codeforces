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
    int n,k;
    cin>>n>>k;
    set<int> st;
    rep(i,n)st.insert(i);
    auto itr = st.begin();
    rep(i,k){
        int x;
        cin>>x;
        int m=st.size();
        x%=m;
        rep(_,x){
            ++itr;
            if(itr==st.end())itr=st.begin();
        }
        cout<<*itr+1<<" ";
        itr=st.erase(itr);
        if(itr==st.end())itr=st.begin();
    }
    return 0;
}