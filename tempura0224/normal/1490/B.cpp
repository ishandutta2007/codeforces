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
        vector<int> cnt(3);
        rep(i,n)cnt[a[i]%3]++;
        int ans = 0;
        while(1){
            if(cnt[0]==cnt[1]&&cnt[1]==cnt[2])break;
            rep(i,3){
                if(cnt[i]>n/3){
                    ans+=cnt[i]-n/3;
                    cnt[(i+1)%3]+=cnt[i]-n/3;
                    cnt[i]=n/3;
                } 
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}