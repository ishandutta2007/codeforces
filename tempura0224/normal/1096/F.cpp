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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

struct BIT{
private:
   int sz;
   vector<ll> node;
public:
   BIT(int n):sz(n),node(n+1){};
   void add(int k,ll x){
       k++;
       while(k<=sz){
           node[k]+=x;
           k+=k&-k;
       }
   }
   ll sum(int k){
       k++;
       ll ret=0;
       while(k>0){
           ret+=node[k];
           k-=k&-k;
       }
       return ret;
   }
   ll sum(int l,int r){
       return sum(r-1)-sum(l-1);
   }
   ll get(int k){
       return sum(k,k+1);
   }
};

bool used[202020];
int sum[202020];
int cnt[202020];
int main(){
    ll inv[202020];
    inv[0]=inv[1]=1;
    for(int i=2;i<202020;++i)inv[i]=mod-(inv[mod%i]*(mod/i))%mod;
    int n;
    cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    BIT bit(n+5);
    ll ans=0;
    int num=0;
    rep(i,n){
        if(a[i]==-1){
            num++;
            continue;
        }
        used[a[i]]=true;
        ans+=(i-num-bit.sum(a[i]));
        ans%=mod;
        bit.add(a[i],1);
    }
    rep(i,n)if(!used[i+1])++cnt[i+1];
    rep(i,n)cnt[i+1]+=cnt[i];
    rep(i,n){
        if(a[i]==-1)++sum[i];
        sum[i+1]=sum[i];
    }

    rep(i,n){
        if(a[i]==-1)continue;
        //cout<<a[i]<<" "<<sum[i]<<" "<<cnt[a[i]]<<endl;
        ll res=(ll)(num-sum[i])*inv[num]%mod*cnt[a[i]]%mod;
        res+=(ll)sum[i]*inv[num]%mod*(num-cnt[a[i]])%mod;
        ans+=res;
        ans%=mod;
    }
    ans+=(ll)num*(num-1)%mod*inv[4]%mod;
    cout<<ans%mod<<endl;
    return 0;
}