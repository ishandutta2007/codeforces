#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
map<ll,ll> cnt;
ll lo, hi, n, k, i, j, x;
bool check(ll m){
        ll wts = 0;
        for(auto v : cnt)
                wts += (v.second/m);
        return wts>=k;
}
int main(){
        for(scanf("%lld%lld",&n,&k),i=1;i<=n;i++){
                scanf("%lld",&x);
                cnt[x]++;
        }
        lo=0,hi=MN;
        while(lo<hi){
                ll m = (lo+hi)/2;
                if(check(m)) lo=m+1;
                else hi=m;
        }
        lo--;
        for(auto v : cnt){
                ll wew = min((v.second/lo),k);
                k -= wew;
                for(int i=0;i<wew;i++)
                        printf("%lld ",v.first);
        }
        printf("\n");
        return 0;
}