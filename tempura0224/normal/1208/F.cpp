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


pair<int,int> marge(pair<int,int> p, pair<int,int> q){
    if(p.first>q.first){
        return {p.first,max(q.first,p.second)};
    }
    else {
        return {q.first,max(p.first,q.second)};
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,n)scanf("%d",&a[i]);
    vector<pair<int,int>> cnt(1<<22,{-1,-1});
    rep(i,n){
        cnt[a[i]]=marge(cnt[a[i]],{i,-1});
    }
    rep(i,22){
        rep(j,1<<22)if(j&(1<<i))cnt[j^(1<<i)]=marge(cnt[j^(1<<i)],cnt[j]);
    }
    int ans = 0;
    rep(i,n-2){
        int cur = 0;
        for(int j=21;j>=0;--j){
            if(a[i]&(1<<j))continue;
            else if(cnt[cur^(1<<j)].second > i)cur^=(1<<j);
        }
        ans = max(ans,a[i]|cur);
    }
    cout<<ans<<endl;
    return 0;
}