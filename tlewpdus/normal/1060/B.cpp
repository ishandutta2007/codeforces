#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll dsum(ll x) {
    ll sum = 0;
    while(x) {
        sum += x%10;
        x/=10;
    }
    return sum;
}

ll md(ll x) {
    ll y = 1;
    while(x) {
        if (x<10) return y-1;
        y*=10;
        x/=10;
    }
    return 0;
}


ll n;
int main() {
    scanf("%lld",&n);
    ll x = md(n);
    printf("%lld\n",dsum(x)+dsum(n-x));

    return 0;
}