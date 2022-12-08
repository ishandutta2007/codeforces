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
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    deque<int> d;
    rep(i,n)d.push_back(a[i]);
    pair<int,int> ans[300001];
    rep(i,300000){
        int x=d.front();d.pop_front();
        int y=d.front();d.pop_front();
        ans[i+1]={x,y};
        d.push_front(max(x,y));
        d.push_back(min(x,y));
    }
    while(q--){
        ll m;
        cin>>m;
        if(m<300000)cout<<ans[m].first<<" "<<ans[m].second<<"\n";
        else {m -= 150000;
        m = m%(n-1)+150000;
        cout<<ans[m].first<<" "<<ans[m].second<<"\n";
        }
    }
    return 0;
}