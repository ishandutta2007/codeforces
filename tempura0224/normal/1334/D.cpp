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
        ll l,r;
        cin>>l>>r;
        int offset = 1;
        --l;
        bool last = false;
        if(r==n*(n-1)+1){
            last = true;
            --r;
        }
        while(r-l>0){
            while(l>=2*n-2){
                l-=2*n-2;
                r-=2*n-2;
                n--;
                offset++;
            }
            REP(i,l,min(r,2*n-2)){
                if(i%2==0)cout<<offset<<" ";
                else cout<<offset+(i+1)/2<<" ";
                l++;
            }
        }
        if(last)cout<<1;
        cout<<endl;
    }
    return 0;
}