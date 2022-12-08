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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> p(n);
    rep(i,n)cin>>p[i];
    vector<int> pos(n);
    rep(i,n){
        pos[--p[i]]=i;
    }
    swap(pos,p);
    vector<int> up(n), down(n);
    rep(i,n-1){
        if(pos[i+1]>pos[i]){
            down[i+1]=down[i]+1;
        } else {
            down[i+1]=0;
        }
        
    }
    for(int i=n-2;i>=0;i--){
        if(pos[i]>pos[i+1]){
            up[i]=up[i+1]+1;
        } else {
            up[i]=0;
        }
    }
    int ma = 0;
    rep(i,n)ma=max(up[i],ma);
    rep(i,n)ma=max(down[i],ma);
    if(ma%2){
        cout<<0<<endl;
        return 0;
    }
    int cnt = 0;
    rep(i,n){
        cnt+=up[i]==ma;
        cnt+=down[i]==ma;
    }
    if(cnt!=2){
        cout<<0<<endl;
        return 0;
    }

    rep(i,n){
        if(up[i]==ma&&down[i]==ma){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}