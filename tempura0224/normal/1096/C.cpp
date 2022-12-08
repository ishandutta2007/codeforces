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
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        bool ok=0;
        for(int i=3;i<=180;++i){
            if(ok)break;
            for(int j=1;j<=i-2;++j){
                if(180*j==i*x){
                    cout<<i<<endl;
                    ok=true;
                    break;
                }
            }
        }
        if(!ok){
            if(x==179)cout<<360<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}