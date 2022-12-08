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
        int n,u,v;
        cin>>n>>u>>v;
        bool same = true, one = true;
        vector<int> a(n);
        rep(i,n)cin>>a[i];
        rep(i,n-1){
            if(abs(a[i+1]-a[i])>1)one=false;
            if(abs(a[i+1]-a[i])>0)same=false;
        }
        if(!one)cout<<0<<endl;
        else if(!same)cout<<min(u,v)<<endl;
        else cout<<v+min(u,v)<<endl;
    }
    return 0;
}