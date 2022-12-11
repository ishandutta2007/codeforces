#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
int n;
ll p[N];
ll r[2], c[2];
ll need;


bool check(int use) {
    ll com = __gcd(c[0], c[1]);
    ll cyc = c[0] * c[1] / com;

    ll tb = use / cyc;
    ll t0 = use / c[0] - tb;
    ll t1 = use / c[1] - tb;

    ll sum = 0;
    for(int i = 1; i <= tb; i++) {
        sum += (r[0] + r[1]) * p[i];
    }
    for(int i = 1; i <= t0; i++) {
        sum += r[0] * p[tb + i];
    }
    for(int i = 1; i <= t1; i++) {
        sum += r[1] * p[tb + t0 + i];
    }
    //cout << use << " " << sum << '\n';
    return (sum / 100) >= need;
}
int solve() {
    sort(p + 1, p + n + 1, greater<int>());
    int L = 0, R = n;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (!check(mid)) L = mid + 1;
        else R = mid - 1;
    }
    if (L > n) return -1;
    return L; 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;

    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> p[i];
        cin >> r[0] >> c[0] >> r[1] >> c[1];
        cin >> need;

        if (r[0] < r[1]) {
            swap(r[0], r[1]);
            swap(c[0], c[1]);
        }

        cout << solve() << '\n';
    }

}