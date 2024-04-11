#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, i, k, x;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld%lld",&k,&x);
        printf("%lld\n",(k-1)*9+x);
    }
    return 0;
}