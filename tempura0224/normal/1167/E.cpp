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
#define int long long
signed main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    rep(i,n)scanf("%lld",&a[i]);
    vector<int> st;
    st.push_back(0);
    vector<int> ok(x+2,0);
    rep(i,n){
        while(st.back()>a[i]){
            ok[st.back()]=inf;
            st.pop_back();
        }
        if(ok[a[i]]!=inf)ok[a[i]]=i;
        st.push_back(a[i]);
    }
    rep(i,x)ok[i+1]=max(ok[i+1],ok[i]);
    vector<int> ok2(x+2,n+1);
    st.clear();
    st.push_back(x+1);
    for(int i=n-1;i>=0;--i){
        while(st.back()<a[i]){
            ok2[st.back()]=-1;
            st.pop_back();
        }
        if(ok2[a[i]]!=-1)ok2[a[i]]=i;
        st.push_back(a[i]);
    }
    for(int i=x;i>0;--i)ok2[i-1]=min(ok2[i],ok2[i-1]);
    ll ans=0;
    rep(i,x){
        int r=x+2,l=i+1;
        while(r-l>1){
            int mid=(l+r)/2;
            if(ok2[mid]==-1)l=mid;
            else if(ok[i]>ok2[mid])l=mid;
            else r=mid;
        }
        ans+=max(0ll,x+2-r);
    }
    cout<<ans<<endl;
    return 0;
}