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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    for(int k=19;k>=1;--k){
        vector<int> used(n);
        vector<int> b=a;
        rep(i,n){
            if(b[i]>=(1<<k))used[i]=2;
        }
        bool ok=true;
        rep(j,k){
            int idx=-1;
            rep(i,n){
                if(!used[i]&&b[i]&(1<<j)){
                    idx=i;break;
                }
            }
            if(idx==-1){
                ok=false;
                break;
            }
            used[idx]=1;
            rep(i,n){
                if(idx!=i && b[i] & (1<<j)) b[i]^=b[idx];
            }
        }
        if(!ok)continue;
        vector<int> c;
        rep(i,n){
            if(used[i]==1){
                assert(b[i]);
                c.push_back(a[i]);
            }
        }
        assert(c.size()==k);
        cout<<k<<endl;
        vector<int> g(1<<k);
        rep(i,1<<k){
            g[i]=i^(i>>1);
        }
        rep(i,1<<k){
            int ret = 0;
            rep(j,k){
                if((1<<j) & g[i])ret^=c[j];
            }
            cout<<ret<<" ";
        }
        cout<<endl;
        return 0;
    }
    cout<<0<<endl;
    cout<<0<<endl;
    return 0;
}