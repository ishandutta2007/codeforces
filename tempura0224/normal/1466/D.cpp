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
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        ll sum = 0;
        rep(i,n)sum+=a[i];
        vector<int> cnt(n);
        priority_queue<ll> pq;
        rep(i,2*n-2){
            int x;
            cin>>x;
            --x;
            if(++cnt[x]>1)pq.push(a[x]);
        }
        rep(i,n-1){
            cout<<sum<<" \n"[i+1==n-1];
            if(i+1!=n-1){
                sum += pq.top();
                pq.pop();
            }
        }
    }
    return 0;
}