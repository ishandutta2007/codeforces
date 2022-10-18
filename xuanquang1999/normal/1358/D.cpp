#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

long long c2(int x) {return 1LL*x*(x+1)/2;}

int n, a[2*MAXN];
long long x;

int main() {
    scanf("%d%lld", &n, &x);
    for(int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);
    for(int i = n; i < 2*n; ++i)
        a[i] = a[i-n];

    long long sumDay = 0, sumHug = 0;
    long long ans = 0;
    int j = 0;
    for(int i = 0; i < 2*n; ++i) {
        sumDay += a[i];
        sumHug += c2(a[i]);
        while (sumDay > x) {
            sumDay -= a[j];
            sumHug -= c2(a[j]);
            ++j;
        }

        long long extra = 0;
        if (j > 0)
            extra = c2(a[j-1]) - c2(a[j-1] - (x - sumDay));
        ans = max(ans, sumHug + extra);
    }

    printf("%lld\n", ans);

    return 0;
}