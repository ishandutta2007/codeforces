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
    int n,q;
    cin>>n>>q;
    vector<int> l(202020,inf), r(202020,-inf),cnt(202020);
    rep(i,n){
        int x;
        cin>>x;
        l[x]=min(l[x],i);
        r[x]=max(r[x],i);
        ++cnt[x];
    }
    vector<int> ord(202020);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return l[x]<l[y];
    });
    int ans = 0;
    int R = -1;
    int ma = 0;
    for(auto i : ord){
        if(l[i]==inf)break;
        if(l[i]<R){
            if(ma>=cnt[i])ans+=cnt[i];
            else {
                ans+=ma;
                ma=cnt[i];
            }
        }
        else {
            ma=cnt[i];
        }
        R = max(r[i],R);
    }
    cout<<ans<<endl;
    return 0;
}