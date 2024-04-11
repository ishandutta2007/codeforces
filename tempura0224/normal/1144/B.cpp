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
    vector<ll> odd,even;
    rep(i,n){
        int x;
        cin>>x;
        if(x%2)odd.push_back(x);
        else even.push_back(x);
    }
    if(odd.size()<even.size())even.swap(odd);
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    if(odd.size()==even.size()){
        cout<<0<<endl;
        return 0;
    }
    int cnt=even.size();
    ++cnt;
    int m=odd.size();
    m-=cnt;
    ll ans=0;
    rep(i,m){
        ans+=odd[i];
    }
    cout<<ans<<endl;
    return 0;
}