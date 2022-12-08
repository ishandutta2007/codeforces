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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rep(i,n)sort(v[i].begin(),v[i].end());
    vector<int> ng,ok;
    rep(i,n)ng.push_back(i);
    rep(i,n)v[i].push_back(inf);
    int ans = 0;
    int i = 0;
    while(!ng.empty()){
        if(i==ok.size()){
            ok.push_back(ng.back());
            ng.pop_back();
            ++ans;
        }
        int x = ok[i++];
        vector<int> nng;
        for(auto e:ng){
            if(v[x].size()&&*lower_bound(v[x].begin(), v[x].end(), e)==e){
                nng.push_back(e);
            }
            else ok.push_back(e);
        }
        ng.swap(nng);
    }
    cout<<ans-1<<endl;
    return 0;
}