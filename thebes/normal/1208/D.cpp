#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const ll MN = 2e5+5;
ll n, i, arr[MN], ans[MN], bit[MN];
void upd(ll p,ll v){for(;p<=n;p+=p&-p)bit[p]+=v;}
ll qu(ll p){ll r=0;for(;p;p-=p&-p)r+=bit[p]; return r;}
set<ll> pos;

int main(){
    scanf("%lld",&n);
    for(i=1;i<=n;i++) upd(i,i);
    for(i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
        pos.insert(i);
    }
    for(i=n;i>=1;i--){
        ll lo=0, hi=n-1;
        while(lo<hi){
            ll m = (lo+hi)/2;
            if(qu(m)>=arr[i]) hi=m;
            else lo=m+1;
        }
        auto it = pos.upper_bound(lo);
        ans[i] = *it;
        upd(*it, -(*it));
        pos.erase(it);
    }
    for(i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}