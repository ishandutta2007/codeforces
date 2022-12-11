#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;

const long long LIM = 1e6;


pll combine(pll a, pll b) {
    return pll(max(a.X, b.X), min(a.Y, b.Y));
}

long long solve(long long type, long long n, long long x, long long k) {
    k += type;
    if (n <= LIM) {
        long long ans = -1;
        for(long long i = type; i <= n; i++) {
            long long rem = k % (n + i);
            if (x + max(i - (n - x), type) <= rem && rem <= x + min(i, x)){
                ans = i;
            }
        }
        return ans;
    }
    long long ans = -1;
    ///no cycle 
    long long pass = x;
    if (pass == 0) pass = n;
    if (pass <= k && 2 * pass >= k) 
        ans = (k - pass) + (n - pass);
    for(long long cycle = 1; cycle * n <= k; cycle++){
        long long dL = (k - 1) / (cycle + 1) - n;
        long long dR = k / cycle - n;
        if (x <= n - x + type) {
            /// 1 -> x
            long long L1 = type, R1 = x;
            long long L2 = (k - cycle * n - x + cycle) / (cycle + 1);
            long long R2 = (k - cycle * n - x - type) / cycle;
            pll res = combine(pll(dL, dR), combine(pll(L1, R1), pll(L2, R2)));
            if (res.X <= res.Y) ans = max(ans, res.Y);
            

            L1 = x , R1 = (n - x + type);
            L2 = (k - cycle * n - 2 * x + cycle - 1) / cycle;
            R2 = (k - cycle * n - x - type) / cycle;
            res = combine(pll(dL, dR), combine(pll(L1, R1), pll(L2, R2)));
            if (res.X <= res.Y) ans = max(ans, res.Y);

            L1 = (n - x + type) , R1 = n;
            L2 = (k - cycle * n - 2 * x + cycle - 1) / cycle;
            R2 = (k - (cycle - 1) * n - 2 * x) / (cycle + 1);
            res = combine(pll(dL, dR), combine(pll(L1, R1), pll(L2, R2)));
            if (res.X <= res.Y) ans = max(ans, res.Y);
         }else {
            /// 1 -> n - x
            long long L1 = type, R1 = n - x + type;
            long long L2 = (k - cycle * n - x + cycle) / (cycle + 1);
            long long R2 = (k - cycle * n - x - type) / cycle;
            pll res = combine(pll(dL, dR), combine(pll(L1, R1), pll(L2, R2)));
            if (res.X <= res.Y) ans = max(ans, res.Y);
            

            L1 = n - x + type, R1 = x;
            L2 = (k - cycle * n - x + cycle) / (cycle + 1);
            R2 = (k - (cycle - 1) * n - 2 * x) / (cycle + 1);
            res = combine(pll(dL, dR), combine(pll(L1, R1), pll(L2, R2)));
            if (res.X <= res.Y) ans = max(ans, res.Y);

            L1 = x , R1 = n;
            L2 = (k - cycle * n - 2 * x + cycle - 1) / cycle;
            R2 = (k - (cycle - 1) * n - 2 * x) / (cycle + 1);
            res = combine(pll(dL, dR), combine(pll(L1, R1), pll(L2, R2)));
            if (res.X <= res.Y) ans = max(ans, res.Y);
        }
    }

    return ans;
}
int main() {
    long long n, tmpl, tmpr, k;
    cin >> n >> tmpl >> tmpr >> k;
    long long x = (tmpr - tmpl + n + 1) % n;
    cout << max(solve(0, n, x, k), solve(1, n, x, k));
}