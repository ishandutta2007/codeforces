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

int calc(int x, int n){
    int ma = (x-1)/2;
    int mi = x-n;
    return max(0,ma-mi+1);
}


vector<int> make(int n, int& m){
    if(n==1)return {1};
    auto v = make(n-1,m);
    if(m==0)return v;
    int nxt = n;
    while(calc(nxt,n-1)>m)++nxt;
    m -= calc(nxt,n-1);
    v.push_back(nxt);
    return v;
}
int main(){
    int n,m;
    cin>>n>>m;
    auto ans = make(n,m);
    if(m>0){
        cout<<-1<<endl;
        return 0;
    }
    int s = ans.size();
    int la = ans[s-1];
    rep(i,n-s){
        ans.push_back((la+1)*(i+2) + 1);
    }
    rep(i,n)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}