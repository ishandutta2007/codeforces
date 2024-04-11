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
#define xx real()
#define yy imag()

const int MAXN = 100005;

long long a[MAXN], d[MAXN], s[MAXN], sd[MAXN];

long long gcd(long long a, long long b){
    return b? gcd(b, a % b) : a;
}

void solve(){
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
    }
    sort(a, a + n);
    s[0] = a[0];
    d[0] = 0;
    sd[0] = 0;
    for(i = 1; i < n; i++){
        s[i] = s[i - 1] + a[i];
        d[i] = (a[i] - a[i - 1]) * i + d[i - 1];
        sd[i] = sd[i - 1] + d[i];
    }
    long long c = s[n - 1] + 2 * sd[n - 1];
    long long dd = (long long)(n);
    long long g = gcd(c, dd);
    c /= g;
    dd /= g;
    printf("%I64d %I64d", c, dd);
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