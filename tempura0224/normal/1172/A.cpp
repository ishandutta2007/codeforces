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
    int a[n],b[n];
    int pos[n];
    rep(i,n){
        cin>>a[i];
        pos[a[i]-1]=i;
    }
    rep(i,n){
        cin>>b[i];
        pos[b[i]-1]=n+i;
    }
    bool valid=true;
    if(pos[0]<n)valid=false;
    if(valid){
        rep(i,2*n-pos[0]){
            if(b[pos[0]-n+i]!=i+1)valid=false;
        }
        REP(i,2*n-pos[0],n){
            if(pos[i]>pos[0]-n+i-1)valid=false;
        }
    }
    if(valid){
        cout<<pos[0]-n<<endl;
        return 0;
    }

    else {
        int ans=n;
        rep(i,n){
            if(pos[i]>=n){
                ans=max(ans,pos[i]-i+1);
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}