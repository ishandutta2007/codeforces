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
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int m = 200001;
    vector<int> isprime(m,true);
    vector<int>prime;
    REP(i,2,m){
        if(!isprime[i])continue;
        prime.push_back(i);
        for(int j=i;j<m;j+=i)isprime[j]=false;
    }
    vector<int> idx(m);
    rep(i,prime.size())idx[prime[i]]=i;
    m=prime.size();
    vector<int> cnt(m), mi(m,inf),smi(m,inf);
    rep(i,n){
        int x = a[i];
        for(auto p:prime){
            if(p*p>x)break;
            if(x%p==0){
                int c=1;
                while(x%p==0){
                    c*=p;
                    x/=p;
                }
                int j = idx[p];
                cnt[j]++;
                if(c<mi[j]){
                    swap(c,mi[j]);
                }
                smi[j]=min(c,smi[j]);
            }
        }
        if(x>1){
            int j = idx[x];
            cnt[j]++;
            int c=x;
            if(c<mi[j]){
                swap(c,mi[j]);
            }
            smi[j]=min(c,smi[j]);
        }
    }
    ll ans = 1;
    rep(i,m){
        if(cnt[i]<n-1)continue;
        else if(cnt[i]==n-1)ans*=mi[i];
        else ans*=smi[i];
    }
    cout<<ans<<endl;
    return 0;
}