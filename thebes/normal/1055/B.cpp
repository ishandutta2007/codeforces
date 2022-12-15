#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int MN = 2e5+5;
ll ds[MN], arr[MN], n, m, l, i, x, y, ans;
ll fnd(ll x){return ds[x]=(ds[x]==x)?x:fnd(ds[x]);}
set<int> wew;
int main(){
    for(scanf("%lld%lld%lld",&n,&m,&l),i=1;i<=n;i++)
        scanf("%lld",&arr[i]), ds[i]=i;
    for(i=2;i<=n;i++){
        if(arr[i]>l&&arr[i-1]>l)
            ds[fnd(i-1)]=fnd(i);
    }
    for(i=1;i<=n;i++){
        if(arr[i]>l) wew.insert(fnd(i));
    }
    ans = wew.size();
    for(;m;m--){
        scanf("%lld",&i);
        if(!i) printf("%lld\n",ans);
        else{
            scanf("%lld%lld",&x,&y);
            if(arr[x]<=l&&arr[x]+y>l){
                ans++;
                if(arr[x+1]>l){
                    ans--;
                    ds[fnd(x)] = fnd(x+1);
                }
                if(arr[x-1]>l){
                    ans --;
                    ds[fnd(x)] = fnd(x-1);
                }
            }
            arr[x] += y;
        }
    }
    return 0;
}