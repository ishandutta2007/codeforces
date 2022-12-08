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
    int ans=0;
    int pre1=-inf,pre2=-inf;
    rep(i,n){
        int x;
        cin>>x;
        if(pre2+x==5){
            cout<<"Infinite"<<endl;
            return 0;
        }
        else if(pre2+x==3){
            if(pre1==3&&pre2==1&&x==2)ans+=2;
            else ans+=3;
        }
        else if(pre2+x==4)ans+=4;
        pre1=pre2,pre2=x;
    }
    cout<<"Finite"<<endl;
    cout<<ans<<endl;
    return 0;
}