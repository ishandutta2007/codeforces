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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<vector<int>> b(505050);
    rep(i,n)b[a[i]].push_back(i);
    rep(i,505050)b[i].push_back(inf);
    vector<int> idx(505050);
    int ma = 0;
    vector<int> c(505050);
    rep(i,s){
        int x;
        cin>>x;
        c[x]++;
        ma = max(ma,b[x][idx[x]++]);
        if(ma==inf){
            cout<<-1<<endl;
            return 0;
        }
    }
    int ans = inf, st = -1,mx = -1;
    rep(i,n){
        int ret = 0;
        int en = ma;
        if(ma-i+1>m){
            ret += ma-i+1-m;
            en = ma-ret;
        }
        if(en/m!=i/m){
            ret += en%m+1;
        }
        if(ret<ans){
            ans = ret;st = i;mx = ma;
        }
        if(c[a[i]])ma = max(ma,b[a[i]][idx[a[i]]++]);
        if(ma==inf){
            break;
        }
    }
    if(ans>n-m*k){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> res;
    for(int i=n-1;i>=0;--i){
        if(i>mx)continue;
        else {
            if(c[a[i]]){
                --c[a[i]];
            }
            else if(ans>0){
                res.push_back(i+1);
                --ans;
            }
        }
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(auto i:res)cout<<i<<" ";
    cout<<endl;
    return 0;
}