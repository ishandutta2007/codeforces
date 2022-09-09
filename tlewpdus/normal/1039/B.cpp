#include <bits/stdc++.h>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k;
char str[10];
int que(ll l, ll r) {
    printf("%lld %lld\n",l+1,r+1);
    fflush(stdout);
    scanf("%s",str);
    if (str[0]=='Y') return 1;
    else if (str[0]=='N') return 0;
    return -1;
}
void bs() {
    ll s = 0, e = n-1;
    int i;
    for (i=0;i<4500;i++) {
        if (s+4*k>=e) {
            ll r = rand()%(e-s+1);
            int v = que(s+r,s+r);
            if (v) return;
        }
        else {
            ll m = (s+e)/2;
            int v = que(s,m);
            if (v) e = m;
            else s = m+1;
        }
        s = max(s-k,0LL);
        e = min(e+k,n-1);
    }
}

int main() {
    scanf("%lld%lld",&n,&k);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    bs();

    return 0;
}