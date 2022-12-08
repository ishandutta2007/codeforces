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
    int d[n], a[n];
    rep(i,n)cin>>d[i]>>a[i];
    queue<int> q;
    rep(i,n){
        if(d[i]==1)q.push(i);
    }
    vector<pair<int,int>> ans;
    while(q.size()){
        int cur = q.front();
        q.pop();
        if(d[cur]==0)continue;
        ans.emplace_back(cur,a[cur]);
        a[a[cur]]^=cur;
        if(--d[a[cur]]==1)q.push(a[cur]);
    }
    cout<<ans.size()<<endl;
    for(auto p : ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
}