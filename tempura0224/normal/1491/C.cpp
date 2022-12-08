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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        rep(i,n)cin>>a[i];
        ll ans = 0;
        set<int> st;
        rep(i,n)st.insert(i);
        st.insert(2*inf);
        rep(i,n){
            if(i+a[i]>=n){
                ans+=i+a[i]-n;
                a[i]=n-i;
            }
            while(a[i]>1){
                ++ans;
                int cur = i;
                while(cur<n){
                    auto itr = st.lower_bound(cur+a[cur]);
                    while(*itr<n&&a[*itr]==1){
                        itr = st.erase(itr);
                    }
                    if(a[cur]>1)--a[cur];
                    cur = *itr;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}