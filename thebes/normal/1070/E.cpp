#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 2e5+5;
ll C, N, M, T, i, lo, hi, d, arr[MN], idk[MN], ans;
ll check(ll m){
    ll r = idk[m], cnt=0, tot=0, cur=0, res=0;
    for(int i=1;i<=N;i++){
        if(arr[i]>r) continue;
        cur += arr[i]; tot += arr[i];
        if(tot<=T) res++;
        cnt = (cnt+1)%M;
        if(!cnt){
            tot += cur;
            cur = 0;
        }
    }
    return res>=m? r:-1;
}
int main(){
    for(scanf("%lld",&C);C;C--){
        for(scanf("%lld%lld%lld",&N,&M,&T),i=1;i<=N;i++)
            scanf("%lld",&arr[i]), idk[i]=arr[i];
        sort(idk+1,idk+N+1);
        lo = 1, hi = N+1; ans = 1;
        while(lo < hi){
            ll m = lo+hi>>1;
            d = check(m);
            if(d != -1) lo = m+1, ans = d;
            else hi=m;
        }
        printf("%lld %lld\n",lo-1,ans);
    }
    return 0;
}