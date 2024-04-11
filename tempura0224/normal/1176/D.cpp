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
    vector<int> prime;
    vector<int> isprime(3000000,0);
    isprime[0]=isprime[1]=1;
    rep(i,3000000){
        if(isprime[i])continue;
        prime.push_back(i);
        for(int j=i;j<3000000;j+=i){
            if(isprime[j]==0)isprime[j]=i;
        }
    }
    int n;
    cin>>n;
    vector<int> cnt(3000000);
    rep(i,2*n){
        int x;cin>>x;
        cnt[x]++;

    }
    for(int i=2999999;i>=0;--i){
        if(!cnt[i])continue;
        if(*lower_bound(prime.begin(),prime.end(),i)!=i){
            rep(j,cnt[i])cout<<i<<" ";
            cnt[i/isprime[i]]-=cnt[i];
            cnt[i]=0;
        }
    }
    rep(i,3000000){
        rep(j,cnt[i])cout<<i<<" ";
        if(cnt[i])cnt[prime[i-1]]-=cnt[i];
    }
    return 0;
}