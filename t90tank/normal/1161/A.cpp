#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

const int maxn = 100006;

int n, k;
int x[maxn];
int f[maxn], l[maxn];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i) {
        f[i] = k+1;
        l[i] = 0;
    }
    for (int i = 1; i <= k; ++i) {
        f[x[i]] = min(f[x[i]], i);
        l[x[i]] = max(l[x[i]], i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == k+1 && l[i] == 0) ans++;
        if (i > 1 && f[i] > l[i-1]) ans++;
        if (i < n && f[i] > l[i+1]) ans++;
    }
    cout<<ans<<endl;
}