
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 1e3 + 5;

int n;
long double a[N], k, ans[N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        ans[i] = k;
        for (int j = 1; j < i; j++){
            if (abs(a[i] - a[j]) > 2 * k) continue;
			ans[i] = max(ans[i], ans[j] + sqrt(4 * k * k - abs(a[i] - a[j]) * abs(a[i] - a[j])));
        }
    }
    cout << fixed << setprecision(6);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}