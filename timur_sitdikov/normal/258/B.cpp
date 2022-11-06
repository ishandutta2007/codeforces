#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

const int maxn = 15;
const long long mod = 1000000007;

long long pow_mod(long long v, long long st){
    long long ans = 1, a = v;
    for(; st; st /= 2){
        if (st & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
    }
    return ans;
}

long long get_obr(long long v){
    return pow_mod(v, mod - 1);
}

long long v[maxn], dig[maxn], lim[maxn], ans, cnt[maxn];

void init(){
    lim[0] = lim[1] = 6;
    lim[2] = 4;
    lim[3] = 3;
    lim[4] = 2;
    lim[5] = lim[6] = lim[7] = lim[8] = lim[9] = 1;
}

long long is_good(long long dig){
    return dig == 4 || dig == 7;
}

long long no_good(long long dig){
    long long ans = dig + 1;
    if (dig >= 4)
        ans--;
    if (dig >= 7)
        ans--;
    return ans;
}

long long good(long long dig){
    long long ans = 0;
    if (dig >= 4)
        ans++;
    if (dig >= 7)
        ans++;
    return ans;
}

void rec_sol(int ind){
    long long i, j;
    if (ind == 10){
        long long vv = 0, sum = 0;
        for(i = 0; i < 10; i++){
            vv += cnt[i] * i;
            sum += cnt[i];
        }
        if (vv < 9 && sum == 6){
            long long s1, s2, s3, s, s0;
            s2 = 0;
            for(i = 9; i > vv; i--){
                s2 += v[i];
            }
            s1 = 1;
            for(i = 0; i < 10; i++){
                s3 = 1;
                for(j = 0; j < cnt[i]; j++){
                    s3 = (s3 * (v[i] - j)) % mod;
                }
                s1 = (s1 * s3) % mod;
            }
            s = (s1 * s2) % mod;
            s0 = 720;
            for(i = 0; i < 10; i++){
                for(j = 1; j <= cnt[i]; j++)
                    s0 /= j;

            }
            ans = (ans + s * s0) % mod;
        }
        return;
    }
    for(i = 0; i <= lim[ind]; i++){
        cnt[ind] = i;
        rec_sol(ind + 1);
    }
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long m, i, j, top, cur, c, k;
    cin >> m;
    init();
    for(i = 0; m; i++){
        dig[i] = m % 10;
        m /= 10;
    }
    top = i;
    cur = 0;
    for(i = top - 1; i >= 0; i--){
        for(j = 0; j <= i; j++){
            c = 1;
            for(k = 1; k <= i; k++)
                c *= k;
            for(k = 1; k <= j; k++)
                c /= k;
            for(k = 1; k <= i - j; k++)
                c /= k;
            v[cur + j] += no_good(dig[i] - 1) * pow_mod(2, j) * pow_mod(8, i - j) * c;
            v[cur + j + 1] += good(dig[i] - 1) * pow_mod(2, j) * pow_mod(8, i - j) * c;
        }
        cur += is_good(dig[i]);
    }
    v[cur]++;
    v[0]--;
    rec_sol(0);
    cout << ans;
}