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
    int a[4];
    rep(i,4){
        cout<<"? "<<i+1<<" "<<i+2<<" "<<endl;
        cin>>a[i];
    }
    vector<int> ans={4,8,15,16,23,42};
    do{
        bool ok=1;
        rep(i,4)if(ans[i]*ans[i+1]!=a[i])ok=false;
        if(ok){
            cout<<"! ";
            rep(i,6)cout<<ans[i]<<" ";
            cout<<endl;
        }
    }while(next_permutation(ans.begin(), ans.end()));

    return 0;
}