#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100006;
int n, m;
int b[maxn];
int g[maxn];

int main() {
    ll s = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &g[i]);
    sort(b+1, b+n+1);
    sort(g+1, g+m+1);
    if (b[n] > g[1]) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) s += ll(b[i])*m;
    for (int i = 2; i <= m; ++i) s += g[i]-b[n];
    if (b[n] != g[1]) s += g[1]-b[n-1];
    cout<<s<<endl;
    return 0;
}