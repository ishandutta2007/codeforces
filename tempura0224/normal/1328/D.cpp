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
        int cnt=  0;
        rep(i,n)cnt += a[i]==a[(i+1)%n];
        if(cnt==n){
            cout<<1<<endl;
            rep(i,n)cout<<1<<" ";
            cout<<endl;
        }
        else if(cnt == 0 && n%2 == 1){
            cout<<3<<endl;
            rep(i,n-1)cout<<1+i%2<<" ";
            cout<<3<<endl;
        }
        else if(n%2 == 1){
            cout<<2<<endl;;
            bool ok=false;
            int c = 1;
            cout<<c<<" ";
            rep(i,n-1){
                if(!ok && a[i]==a[i+1]){
                    cout<<c<<" ";
                    ok=true;
                }
                else {
                    c = 3-c;
                    cout<<c<<" ";
                }
            }
            cout<<endl;
        }
        else {
            cout<<2<<endl;
            rep(i,n)cout<<i%2+1<<" ";
            cout<<endl;
        }
    }
    return 0;
}