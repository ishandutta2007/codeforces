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
        vector<int> x(n),y(n);
        rep(i,n)cin>>x[i]>>y[i];
        bool ok=true;
        rep(i,n)rep(j,n){
            if(x[i]<x[j]&&y[i]>y[j]){
                ok=false;
            }
        }
        if(!ok){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            vector<int> ord(n);
            rep(i,n)ord[i]=i;
            sort(ord.begin(),ord.end(),[&](int p,int q){
                return x[p]==x[q]?y[p]<y[q]:x[p]<x[q];
            });
            int cx=0,cy=0;
            for(auto i:ord){
                REP(j,cx,x[i])cout<<"R";
                REP(j,cy,y[i])cout<<"U";
                cx=x[i];cy=y[i];
            }
            cout<<endl;
        }
    }
    return 0;
}