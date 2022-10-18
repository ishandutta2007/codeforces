#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const long long oo = (long long)1e18 + 7;

typedef long long ll;

int n, a[MAXN];
ll d[MAXN];


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    d[0] = a[0];
    for(int i = 1; i < n; ++i)
        d[i] = d[i-1] + a[i];

    vector<ll> primeDiv;

    long long x = d[n-1];
    for(long long i = 2; i*i <= x; ++i) {
        if (x%i == 0) {
            primeDiv.push_back(i);
            while (x%i == 0)
                x /= i;
        }
    }

    if (x > 1)
        primeDiv.push_back(x);    

    long long ans = oo;

    for(long long x: primeDiv) {
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            long long r = d[i] % x;
            sum += min(r, x - r);
        }
        ans = min(ans, sum);
    }

    if (ans == oo)
        ans = -1;

    printf("%lld\n", ans);

    return 0;
}