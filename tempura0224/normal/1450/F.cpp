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
        vector<int> cnt(n+1);
        rep(i,n)cnt[a[i]]++;
        bool can=true;
        rep(i,n+1){
            if(2*cnt[i]>n+1)can=false;
        }
        if(!can){
            cout<<-1<<endl;
            continue;
        }
        rep(i,n+1)cnt[i]=0;
        int l=0;
        int sum = 1;
        rep(i,n-1){
            if(a[i]==a[i+1]){
                cnt[a[l]]++;
                cnt[a[i]]++;
                l=i+1;
                ++sum;
            }
        }
        cnt[a[l]]++;
        cnt[a[n-1]]++;
        int ma = 0;
        rep(i,n+1)ma=max(cnt[i],ma);
        int mv=0;
        rep(i,n+1)if(ma==cnt[i])mv=i;
        int res = 2*sum-ma;
        ma -= res;
        if(ma<=2){
            cout<<sum-1<<endl;
            continue;
        }
        int cnt2=0, cnt1=0;
        rep(i,n-1){
            if(a[i]!=a[i+1]&&a[i]!=mv&&a[i+1]!=mv)++cnt2;
        }
        int ans = sum-1;
        while(cnt2 && ma>2){
            --cnt2;
            ++ans;
            ma-=2;
        }
        if(ma>2)ans+=ma-2;
        cout<<ans<<endl;
    }
    return 0;
}