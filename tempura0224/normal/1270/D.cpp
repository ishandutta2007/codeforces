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
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    rep(i,k+1){
        cout<<"? ";
        rep(j,k+1){
            if(j!=i)cout<<j+1<<" ";
        }
        cout<<endl;
        ll x,y;
        cin>>x>>y;
        mp[y]++;
    }
    auto itr = prev(mp.end());
    cout<<"! "<<itr->second<<endl;
    
    return 0;
}