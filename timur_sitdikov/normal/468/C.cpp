#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

const int SZ = 3;
const ll BASE = 1e9;

struct BigInt{
    ll m[SZ];
    BigInt(){
        for(int i = 0; i < SZ; i++){
            m[i] = 0;
        }
    }
};

BigInt operator + (const BigInt &a, const BigInt &b){
    BigInt ans;
    ll t = 0;
    for(int i = 0; i < SZ; i++){
        ans.m[i] = a.m[i] + b.m[i] + t;
        if (ans.m[i] >= BASE){
            ans.m[i] -= BASE;
            t = 1;
        } else {
            t = 0;
        }
    }
    return ans;
}

BigInt operator - (const BigInt &a, const BigInt &b){
    BigInt ans;
    ll t = 0;
    for(int i = 0; i < SZ; i++){
        ans.m[i] = a.m[i] - b.m[i] - t;
        if (ans.m[i] < 0){
            ans.m[i] += BASE;
            t = 1;
        } else {
            t = 0;
        }
    }
    return ans;
}

BigInt operator * (const BigInt &a, ll b){
    BigInt ans;
    ll t = 0;
    for(int i = 0; i < SZ; i++){
        ans.m[i] = a.m[i] * b + t;
        t = ans.m[i] / BASE;
        ans.m[i] %= BASE;
    }
    return ans; 
}

BigInt set_val(ll v){
    BigInt ans;
    for(int i = 0; v; i++, v /= BASE){
        ans.m[i] = v % BASE;
    }
    return ans;
}

bool operator < (const BigInt &a, const BigInt &b){
    for(int i = SZ - 1; i >= 0; i--){
        if (a.m[i] != b.m[i]){
            return a.m[i] < b.m[i];
        }
    }
    return false;
}

const ll LIM = 1e18 * 4;
const int MAX1 = 172;

ll rem[MAX1], val[MAX1];

BigInt st10[20];

ll dig[25];

BigInt calc(ll v){
    int i, n;
    v++;
    for(i = 0; v; i++, v /= 10){
        dig[i] = v % 10;
    }
    n = i;
    BigInt ans, tmp, tmp1;
    ll sum_pref = 0, tmp_ll;
    for(i = n - 1; i >= 0; i--){
        tmp_ll = sum_pref * dig[i];
        tmp = st10[i] * tmp_ll;
        ans = ans + tmp;

        tmp_ll = dig[i] * (dig[i] - 1ll) / 2ll;
        tmp = st10[i] * tmp_ll;
        ans = ans + tmp;

        tmp_ll = 45ll * dig[i] * i;
        tmp = st10[i - 1] * tmp_ll;
        ans = ans + tmp;

        sum_pref = sum_pref + dig[i];
    }
    return ans;
}

void get_rem(BigInt &a, int ind){
    int i, j;
    BigInt tmp;
    ll l = 0, r = LIM;
    for(; l + 1 < r; ){
        ll mid = (l + r) >> 1;
        tmp = calc(mid);
        if (tmp < a){
            l = mid;
        } else {
            r = mid;
        }
    }
    tmp = calc(r);
    BigInt tmp1 = tmp - a;
    rem[ind] = tmp1.m[0];
    val[ind] = r;
    return;
}


void solve(){
    ll a;
    BigInt _a, _a1;
    cin >> a;
    if (a == 1){
        printf("1 1\n");
        return;
    }
    _a = set_val(a);    
    st10[0] = set_val(1ll);
    for(int i = 1; i < 20; i++){
        st10[i] = st10[i - 1] * 10ll;   
    }
    for(int i = 1; i < MAX1; i++){
        _a1 = _a1 + _a;
        get_rem(_a1, i);
    }
    rem[0] = 0;
    val[0] = 0;
    for(int i = 1; i < MAX1; i++){
        for(int j = i + 1; j < MAX1; j++){
            if (rem[i] == rem[j]){
                printf("%lld %lld\n", val[i] + 1, val[j]);
                return;
            }
        }
    }
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}