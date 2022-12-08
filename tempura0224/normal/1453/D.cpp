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
        ll n;
        cin>>n;
        if(n%2){
            cout<<-1<<endl;
            continue;
        }
        n/=2;
        vector<int> ans;
        ll cur = 1ll<<60;
        int c = 60;
        while(cur>=2){
            ll tmp = cur-1;
            while(n>=tmp){
                n-=tmp;
                ans.push_back(1);
                rep(j,c-1)ans.push_back(0);
            }
            cur>>=1;
            --c;
        }
        cout<<ans.size()<<endl;
        for(auto e: ans)cout<<e<<" ";
        cout<<endl;
    }
    return 0;
}