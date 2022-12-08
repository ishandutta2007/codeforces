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
        int p[n];
        rep(i,n)cin>>p[i];
        int q[n], r[n];
        rep(i,n)q[i]=(p[i]-i+n)%n;
        rep(i,n)r[i]=(p[i]+i)%n;
        bool ok =true;
        rep(i,n-1)if(q[i]!=q[i+1])ok=false;
        if(ok){
            cout<<"YES"<<endl;
            continue;
        }
        ok =true;
        rep(i,n-1)if(r[i]!=r[i+1])ok=false;
        if(ok){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}