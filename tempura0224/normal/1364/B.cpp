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
        vector<int> b;
        b.push_back(a[0]);
        REP(i,1,n-1){
            if(a[i-1]<a[i] != a[i]<a[i+1]){
                b.push_back(a[i]);
            }
        }
        b.push_back(a[n-1]);
        cout<<b.size()<<endl;
        for(auto e:b)cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}