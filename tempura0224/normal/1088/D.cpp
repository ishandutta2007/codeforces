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
    cout<<"? 0 0"<<endl;
    int x;cin>>x;
    bool large;
    large=(x>=0);
    int res1=0,res2=0;
    for(int i=29;i>=0;--i){
        int ret1,ret2;
        cout<<"? "<<res1<<" "<<(res2^(1<<i))<<endl;
        cin>>ret1;
        cout<<"? "<<(res1^(1<<i))<<" "<<res2<<endl;
        cin>>ret2;
        ret1=(ret1>=0),ret2=(ret2>=0);
        if(ret1==ret2){
            if(large)res1|=(1<<i);
            else res2|=(1<<i);
            large=ret1;
        }
        else {
            if(ret1){
                res1|=(1<<i);
                res2|=(1<<i);
            }
        }
    }
    cout<<"! "<<res1<<" "<<res2<<endl;
    return 0;
}