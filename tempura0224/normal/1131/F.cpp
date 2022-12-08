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
    vector<int> a[n];
    int par[n];
    rep(i,n){
        a[i].push_back(i);
        par[i]=i;
    }
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        --x;--y;
        x=par[x],y=par[y];
        if(a[x].size()<a[y].size())swap(x,y);
        for(auto e : a[y]){
            par[e]=x;
            a[x].push_back(e);
        }
        a[y].clear();
    }
    int ret=par[0];
    rep(i,n){
        printf("%d ",a[ret][i]+1);
    }
    cout<<endl;
    return 0;
}