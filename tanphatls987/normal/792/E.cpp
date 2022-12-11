#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e16 + 10;
const int N = 5e2 + 10;

int n, a[N];

ll check(ll low) {
    if (low == 0) return inf;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll gr = a[i] / low;
        ll rem = a[i] % low;
        if (rem > gr) return inf;
        
        ll n1 = gr - rem;
        ans += gr - n1 / (low + 1); 
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    long long ans = inf;

    for(int i = 1; i * i <= a[1]; i++) {
        ans = min(ans, check(i));
        ans = min(ans, check(a[1] / i));
        ans = min(ans, check(a[1] / i - 1));
    }
    cout << ans;
}