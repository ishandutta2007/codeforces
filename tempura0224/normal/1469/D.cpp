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
        vector<int> a(n+1);
        rep(i,n+1)a[i]=i;
        vector<pair<int,int>> ans;
        for(ll i=n-1;i>=2;i--){
            while(i<=(a[n]+i-1)/i ){
                ans.emplace_back(n, i);
                a[n]=(a[n]+i-1)/i;
            }
            ans.emplace_back(i,n);
            a[i]=(a[i]+a[n]-1)/a[n];
        }
        cout<<ans.size()<<endl;
        rep(i,n){
            assert(a[i+1]==1+(i+1==n));
        }
        assert(ans.size()<n+5);
        for(auto p: ans){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    return 0;
}