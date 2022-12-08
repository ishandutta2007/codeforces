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
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<3<<endl;
        return 0;
    }
    if(k==2){
        cout<<6<<endl;
        return 0;
    }
    int m = 1e6+1;
    vector<int> prime, isprime(m,0);
    isprime[0]=isprime[1]=inf;
    rep(i,m){
        if(isprime[i])continue;
        prime.push_back(i);
        for(int j = i;j<m; j+=i){
            isprime[j]=i;
        }
    }
    vector<int> cnt(m);
    rep(i,m)cnt[i]=i;
    for(auto p : prime){
        int t = (m-1)/p;
        for(int j = t;j>0;--j)cnt[j*p]-=cnt[j];
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto p : prime){
        if(p==2)continue;
        pq.push({cnt[p],p});
    }
    pq.push({3,4});
    ll ans = 1;
    vector<int> used(m,0);
    rep(i,k){
        auto p = pq.top();pq.pop();
        ans += p.first;
        for(auto e : prime){
            if(e>isprime[p.second])break;
            if(e*p.second>n)break;
            if(used[e*p.second])continue;
            pq.push({cnt[e*p.second],e*p.second});
            used[e*p.second]=true;
        }
    }
    cout<<ans<<endl;
    return 0;
}