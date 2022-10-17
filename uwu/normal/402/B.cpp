#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001;

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int best = n - 1, idx = 1;
    for (int i = 1; i <= n; ++i){
        int val = a[i] - i * k;
        if (val + k <= 0) continue;
        int cur = 0;
        for (int j = 1; j <= n; ++j){
            val += k;
            cur += a[j] != val;
        }
        if (cur < best){
            best = cur;
            idx = i;
        }
    }
    int val = a[idx] - idx * k;
    cout << best << '\n'; 
    for (int i = 1; i <= n; ++i){
        val += k;
        if (a[i] < val) cout << "+ " << i << " " << val - a[i] << '\n';
        if (a[i] > val) cout << "- " << i << " " << a[i] - val << '\n';
    }
}