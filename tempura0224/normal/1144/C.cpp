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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    vector<int> ret1,ret2;
    map<int,int> mp;
    rep(i,n){
        int x;
        cin>>x;
        if(mp[x]==0){
            ret1.push_back(x);
        }
        else if(mp[x]==1){
            ret2.push_back(x);
        }
        else {
            cout<<"NO"<<endl;
            return 0;
        }
        ++mp[x];
    }
    sort(ret1.begin(),ret1.end());
    sort(ret2.rbegin(),ret2.rend());
    cout<<"YES"<<endl;
    cout<<ret1.size()<<endl;
    for(auto p : ret1){
        cout<<p<<" ";
    }
    cout<<endl;
    cout<<ret2.size()<<endl;
    for(auto p : ret2){
        cout<<p<<" ";
    }
    cout<<endl;

    return 0;
}