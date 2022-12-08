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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;



ll a[101010];
ll x,y;

ll dfs(int l,int r,int k){
    if(l==r){
        return x;
    }

    if(k==-1){

        return (r-l)*y;
    }
    int mid=l;
    for(int i=l;i<r;++i){
        if(a[i]&(1<<k)){
        }
        else{
            ++mid;
        }
    }
    ll ret=(r-l)*y*(1<<(k+1));
    ret=min(ret,dfs(l,mid,k-1)+dfs(mid,r,k-1));
    return ret;
}

int main(){
    int n,k;
    cin>>n>>k>>x>>y;
    rep(i,k){
        cin>>a[i];
        --a[i];
    }
    sort(a,a+k);
    cout<<dfs(0,k,n-1)<<endl;
    return 0;
}