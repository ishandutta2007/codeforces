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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m = 4*n;
        int a[m];
        rep(i,m)scanf("%d",&a[i]);
        sort(a,a+m);
        set<int> st;
        bool ok=true;
        rep(i,n){
            if(a[2*i]!=a[2*i+1]||a[m-2*i-1]!=a[m-2*i-2]){
                ok=false;
                break;
            }
            st.insert(a[2*i]*a[m-2*i-2]);
        }
        if(st.size()!=1)ok=false;
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}