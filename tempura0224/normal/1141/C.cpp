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
    int a[n-1];
    rep(i,n-1)cin>>a[i];
    ll cur=0,ma=0,mi=0;
    rep(i,n-1){
        cur+=a[i];
        ma=max(ma,cur);
        mi=min(mi,cur);
    }
    if(ma-mi!=n-1){
        cout<<-1<<endl;
        return 0;
    }
    int ans=-mi+1;
    vector<int> res;
    vector<int> used(n+1);
    used[ans]=1;
    res.push_back(ans);
    rep(i,n-1){
        ans+=a[i];
        if(used[ans]||ans<1||ans>n){
            cout<<-1<<endl;
            return 0;
        }
        used[ans]=1;
        res.push_back(ans);
    }
    for(auto i : res)cout<<i<<" ";
    cout<<endl;
    return 0;
}