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
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> cnt(2);
    rep(i,n){
        cnt[a[i]]++;
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            --x;
            if(a[x]==0){
                --cnt[0];++cnt[1];
                a[x]=1;
            } else {
                --cnt[1];++cnt[0];
                a[x]=0;
            }
        } else {
            int x;
            cin>>x;
            if(x<=cnt[1])cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}