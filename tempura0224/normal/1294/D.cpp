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
    int q,m;
    cin>>q>>m;
    vector<int> cnt(m);
    vector<set<int>> st(q+1);
    rep(i,m)st[0].insert(i);
    int mi = 0;
    while(q--){
        int x;
        cin>>x;
        x%=m;
        st[cnt[x]++].erase(x);
        st[cnt[x]].insert(x);
        while(st[mi].empty())++mi;
        cout<<mi*m+*st[mi].begin()<<"\n";

    }
    return 0;
}