// Author: wlzhouzhuan
// naive xay5421
#include <bits/stdc++.h>
using namespace std;

#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double alpha = 1.618;

ll n;
int type, times;

int ask(ll x) {
    
    times++;
//    if (times >= 105) puts("WA"), exit(0);
    
    if (type) { //  
        return x <= n;
    } else { //  
        printf("? %lld\n", x), fflush(stdout);
        char _[6]; scanf("%s", _);
        return _[0] == 'L';
    }
}
void solve() {
    
    if (type) scanf("%lld", &n);
    times = 0;
    
    ll l = 0, r = 1e14, cur = 1;
    while (l < r) {
        ll mid;
        if (cur >= (105 - times) * r) mid = l + (r - l) / 2;
        else if (cur >= 5 * r) mid = l + (r - l) * 0.4;
        else mid = l + (r - l) * 0.25;
        mid = min(mid + 1, cur);
        mid = max(mid, l);
        if (ask(mid) == 0) {
            cur -= mid;
            r = min(r, mid - 1); 
        } else {
            cur += mid;
            l = mid;
        }
    }
    printf("! %lld\n", r), fflush(stdout);
    if (type) printf("time used = %lld\n", times);
}
int main() {
    type = 0;
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}