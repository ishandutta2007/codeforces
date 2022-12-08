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

int maxN = 10000007;
int main(){
    int n;
    cin>>n;
    int a[n];
    vector<ll> cnt(maxN);
    rep(i,n){
        cin>>a[i];
        ++cnt[a[i]];
    }
    vector<int> isprime(maxN,1),meb(maxN,1);
    isprime[0]=isprime[1]=0;
    meb[0]=0;
    vector<int> prime;
    rep(i,maxN){
        if(!isprime[i])continue;
        prime.push_back(i);
        for(int j=i;j<maxN;j+=i){
            isprime[j]=false;
            meb[j]*=-1;
        }
        for(ll j=(ll)i*i ; j<maxN; j+=(ll)i*i){
            meb[j]=0;
        }
    }
    for(auto p : prime){
        for(int j=maxN/p*p;j>0;j-=p){
            cnt[j/p]+=cnt[j];
        }
    }
    vector<ll> pw(1<<20);
    pw[0]=1;
    rep(i,n)pw[i+1]=2*pw[i]%mod;
    vector<ll> dp1(maxN);
    rep(i,maxN){
        dp1[i]=(mod+meb[i]*(pw[cnt[i]]-1))%mod;
    }
    ll res=0;
    rep(i,maxN)res+=dp1[i];
    res%=mod;
    rep(i,maxN){
        if(cnt[i])dp1[i]=(mod+meb[i]*(pw[cnt[i]-1]))%mod;
        else dp1[i]=0;
    }
    for(auto p : prime){
        for(int i=1;i<=(maxN-1)/p;++i)(dp1[p*i]+=dp1[i])%=mod;
    }
    ll ans=0;
    rep(i,n)ans+=(2*dp1[a[i]]-res+mod);
    cout<<ans%mod<<endl;
    return 0;
}