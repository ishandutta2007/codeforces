#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 150005;
ll n, i, a[N], b[N], res;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        res = __gcd(res, a[i]*b[i]);
    }
    for(i=1;i<=n;i++){
        if(__gcd(res,a[i])>1) res = __gcd(res,a[i]);
        else if(__gcd(res,b[i])>1) res = __gcd(res,b[i]);
        else{printf("-1\n"); return 0;}
    }
    printf("%lld\n",res);
    return 0;
}