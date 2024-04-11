#include <bits/stdc++.h>
using namespace std;

long long a, b, x, y, ans1, ans2, g;

int main(){
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    g = __gcd(x,y); x/=g; y/=g;
    ans1 = a/x; ans2 = b/y;
    printf("%lld\n",min(ans1,ans2));
    return 0;
}