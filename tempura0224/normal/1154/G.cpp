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

ll a[1234567];

void calc(pair<int,int>& p, pair<int,int> q){
    if(a[p.first]>a[q.first])swap(p,q);
    if(a[p.second]>a[q.first])p.second=q.first;
}


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> p(12345678,{n,n});
    a[n]=inf;
    rep(i,n){
        scanf("%lld",&a[i]);
        calc(p[a[i]],{i,n});
    }

    for(int i=1;i<=10000000;++i){
        for(int j=2*i;j<=10000000;j+=i){
            calc(p[i],p[j]);
        }
    }
    ll ans=longinf;
    int x,y;
    for(int i=1;i<=10000000;++i){
        if(p[i].first==n||p[i].second==n)continue;
        if(a[p[i].first]*a[p[i].second]/i<ans){
            ans=a[p[i].first]*a[p[i].second]/i;
            x=min(p[i].first,p[i].second);
            y=max(p[i].first,p[i].second);
        }
    }
    cout<<x+1<<" "<<y+1<<endl;
    return 0;
}