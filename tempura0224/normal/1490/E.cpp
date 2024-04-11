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
        vector<int> ord(n);
        rep(i,n)ord[i]=i;
        sort(ord.begin(),ord.end(),[&](int x, int y){
            return a[x]<a[y];
        });
        vector<int> ans;
        ll sum = 0;
        rep(i,n){
            ans.push_back(ord[i]);
            sum += a[ord[i]];
            if(i+1<n&&sum<a[ord[i+1]]){
                while(ans.size())ans.pop_back();
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto e: ans)cout<<e+1<<" ";
        cout<<endl;
    }
    return 0;
}