#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

#define X first
#define Y second
const int N = 5e5 + 10;

int n;
ll sum;
ii a[N];


bool check(int mid) {
    ll rem = sum, acc = (n + 1) / 2;
    for(int i = n; i >= 1; i--) {
        ll cost = a[i].X;
        if (acc > 0 && a[i].X < mid && a[i].Y >= mid) 
            cost = mid;
        rem -= cost;
        acc -= (cost >= mid);
    }
    return acc <= 0 && rem >= 0;
}
ll solve() {
    int L = 1, R = 1e9 + 10;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) L = mid + 1;
        else R = mid - 1;
    }
    return R;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> sum;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].X >> a[i].Y;
        }
        sort(a + 1, a + n + 1);
        cout << solve() << '\n';
    }
}