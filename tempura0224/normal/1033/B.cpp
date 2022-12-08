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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        if(a-b>1){
            cout<<"NO"<<endl;
            continue;
        }
        ll c=a+b;
        bool p=true;
        REP(i,2,1000000){
            if(c==i)break;
            if(c%i==0){
                cout<<"NO"<<endl;
                p=false;
                break;
            }
        }
        if(p)cout<<"YES"<<endl;
    }
    return 0;
}