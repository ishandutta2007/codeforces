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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int m = n/k;
        vector<vector<int>> cnt(k,vector<int>(26));
        rep(i,n){
            cnt[min(i%k,k-1-i%k)][s[i]-'a']++;
        }
        int ans = 0;
        rep(i,(k+1)/2){
            ans += -*max_element(cnt[i].begin(),cnt[i].end());
        }
        cout<<n+ans<<endl;
    }
    return 0;
}