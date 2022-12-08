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

int main(){
    int n,t;
    cin>>n>>t;
    ll a[n];
    int b=512;
    rep(i,n)scanf("%lld",&a[i]);
    int left[t],right[t];
    rep(i,t){
        scanf("%d%d",&left[i],&right[i]);
        --left[i];
    }

    vector<int> ord(t);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        if(left[x]/b!=left[y]/b) return left[x]<left[y];
        return right[x] < right[y]; 
    });
    ll ret=0;
    int l=0,r=0;
    vector<ll> cnt(1234567);
    ll ans[t];
    for(auto i:ord){
        while(r<right[i]){
            ++cnt[a[r]];
            ret+=(2*cnt[a[r]]-1)*a[r];
            ++r;
        }
        while(r>right[i]){
            --r;
            ret-=(2*cnt[a[r]]-1)*a[r];
            --cnt[a[r]];
        }
        while(l<left[i]){
            ret-=(2*cnt[a[l]]-1)*a[l];
            --cnt[a[l]];
            ++l;
        }
        while(l>left[i]){
            --l;
            ++cnt[a[l]];
            ret+=(2*cnt[a[l]]-1)*a[l];
        }
        ans[i]=ret;
    }
    rep(i,t){
        printf("%lld\n",ans[i]);
    }
    return 0;
}