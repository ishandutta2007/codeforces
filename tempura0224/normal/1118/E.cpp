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
    ll m,n;
    cin>>m>>n;
    if(m>n*n-n){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    vector<pint> ans;
    int idx1=1,idx2=2;
    rep(i,m){
        ans.emplace_back(idx1,idx2);
        ++idx1;
        ++idx2;
        if(idx1==n+1)idx1=1;
        if(idx1==1)++idx2;
        if(idx2>=n+1)idx2-=n;
    }
    rep(i,m){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}