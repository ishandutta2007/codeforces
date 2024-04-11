#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll fact(ll n){return n==0?1LL:(n*fact(n-1))%mod;}
ll fact2(ll n,ll l){return n==l?l:(n*fact2(n-1,l))%mod;}
ll n, i, ans, f2, f1;

int main(){
    scanf("%lld",&n);
    ans += fact(n);
    f1 = fact(n); f2 = 1;
    for(i=1;i<n;i++){
        f2 = (f2*(n-i+1))%mod;
        ans = (ans+f1-f2+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}