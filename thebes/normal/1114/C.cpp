#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, b, r, i, j, ans = 1LL<<60;
ll solve(ll p){
    ll tmp = n, ret = 0;
    while(tmp){
        ret += (tmp / p);
        tmp /= p;
    }
    return ret;
}
int main(){
    scanf("%lld%lld",&n,&b);r=b;
    for(i=2;i*i<=b;i++){
        if(r%i==0){
            ll cnt = 0;
            while(r % i==0) r /= i, cnt ++;
            ans = min(ans, (solve(i)/cnt));
        }
    }
    if(r != 1){
        ans = min(ans, solve(r));
    }
    printf("%lld\n",ans);
    return 0;
}