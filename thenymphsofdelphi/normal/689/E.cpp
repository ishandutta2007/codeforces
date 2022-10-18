#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 200005, mod = 1000000007;

int pow2(int a, int b){
    int ans = 1;
    while (b){
        if (b & 1){
            ans = (ans * a) % mod;
        }
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

int f[N], c[N];
map <int, int> a;

int C(int n, int k){
    int ans = (f[n] * c[k]) % mod;
    return (ans * c[n - k]) % mod;
}

signed main(){
    int n, k;
    int ans = 0;
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    assert(1 <= k && k <= n && n <= 2e5);
    f[0] = 1;
    c[0] = 1;
    for (int i = 1; i <= n; i++){
        f[i] = (f[i - 1] * i) % mod;
        c[i] = pow2(f[i], mod - 2);
    }
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        assert(-1e9 <= x && x <= y && y <= 1e9);
        a[x]++;
        a[y + 1]--;
    }
    int l = a.begin() -> fi, sum = 0;
    for (auto it : a){
        int dist = it.fi - l;
        if (sum >= k){
            ans += (C(sum,k) * dist) % mod;
        }
        ans = (ans >= mod ? ans - mod : ans);
        sum += it.se;
        l = it.fi;
    }
    cout << ans;
}