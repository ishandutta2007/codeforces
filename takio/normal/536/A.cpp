#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

const int N = 1000100;
LL s[N], sum[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    LL a, b;
    cin >> a >> b >> n;
    s[1] = sum[1] = a;
    for (int i = 2; i < N; i++) {
        s[i] = s[i - 1] + b;
        sum[i] = sum[i - 1] + s[i];
    }
    int l, t, m;
    while (n--) {
        scanf ("%d%d%d", &l, &t, &m);
        if (s[l] > t) { printf ("%d\n", -1); continue; }
        int r = N;
        LL all = 1LL * t * m + sum[l - 1];
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (s[m] <= t && sum[m] <= all) l = m;
            else r = m;
        }
        printf ("%d\n", l);
    }
}