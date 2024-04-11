#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <complex>
using namespace std;

#define pb push_back 
#define mp make_pair

#define point complex<double>
#define xx real()
#define yy imag()

const long long MOD = 1000000007;

const int MAXN = 100005;

long long pow_mod(long long v, long long st){
    long long ans = 1, a = v;
    for(; st; st /= 2){
        if (st & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

long long get_inv(long long v){
    return pow_mod(v, MOD - 2);
}

long long f[MAXN], of[MAXN];

long long get_c(long long n, long long m){
    if (n < m || m < 0){
        return 0;
    }
    long long ans = f[n];
    ans = (ans * of[m]) % MOD;
    ans = (ans * of[n - m]) % MOD;
    return ans;
}

pair<int, int> vals[MAXN];
int n, s;

long long calc(int l, int r){
    long long ans, tmp;
    int i, len, last, cur_pos, offset;
    if (l < 0 || r >= n){
        return 0;
    }
    len = r - l;
    if (l < r){
        ans = 0;
        for(i = 0; i < len; i++){
            ans = (ans + get_c(len - 1, i)) % MOD;
        }
    }
    else {
        ans = 1;
    }
    last = vals[s].first;
    for(i = s + 1; i < n; i++){
        offset = vals[i].first - last;
        cur_pos = vals[i].second;
        if (l <= cur_pos && cur_pos <= r){
            return 0;
        }
        if (cur_pos < l){
            len = l - cur_pos;
            ans = (ans * get_c(offset - 1, len - 1)) % MOD;
            l = cur_pos;
            r += offset - len;
        }
        else {
            len = cur_pos - r;
            ans = (ans * get_c(offset - 1, len -1)) % MOD;
            r = cur_pos;
            l -= offset - len;
        }
        last = vals[i].first;
    }
    ans = (ans * get_c(n - last, l));
    return ans;
}

void solve(){
    int i, l, r, last, tmp;
    long long ans;
    scanf("%d", &n);
    f[0] = 1;
    for(i = 1; i <= n; i++){
        f[i] = (f[i - 1] * i) % MOD;
    }
    of[n] = get_inv(f[n]);
    for(i = n - 1; i >= 0; i--){
        of[i] = (of[i + 1] * (i + 1)) % MOD;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &vals[i].first);
        vals[i].second = i;
    }
    sort(vals, vals + n);
    for(i = 0; i < n; i++){
        if (vals[i].first > 0){
            break;
        }
    }
    if (i == n){
        ans = pow_mod(2, n - 1);
        cout << ans;
        return;
    }
    s = i;
    tmp = vals[s].first;
    if (tmp == 1){
        ans = calc(vals[i].second, vals[i].second);
    }
    else {
        ans = calc(vals[i].second - tmp + 1, vals[i].second);
        ans = (ans + calc(vals[i].second, vals[i].second + tmp - 1)) % MOD;
    }
    cout << ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}