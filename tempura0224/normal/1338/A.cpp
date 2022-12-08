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
        int ans = 100;
        bool ok=true;
        rep(i,n-1){
            if(a[i]>a[i+1])ok=false;
        }
        if(ok){
            cout<<0<<endl;
            continue;
        }
        vector<ll> b(n+1);
        for(int i=40;i>=0;i--){
            b[n]=longinf;
            ok=true;
            for(int j=n-1;j>=0;--j){
                if(a[j]>b[j+1]){
                    ok=false;
                    break;
                }
                b[j]=a[j];
                for(int k=i;k>=0;--k){
                    if(b[j]+(1ll<<k)<=b[j+1])b[j]+=1ll<<k;
                }
            }
            if(!ok)break;
            else ans=i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}