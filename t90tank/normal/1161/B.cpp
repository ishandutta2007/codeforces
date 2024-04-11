#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

const int maxn = 100006;

int n, m;
vi a[maxn];
int p[maxn];

bool same(vi x, vi y) {
    if (x.size() != y.size()) return false;
    for (int i = 0; i < (int)x.size(); ++i)
        if (x[i] != y[i]) return false;
    return true;
}

int main() {
    scanf( "%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x,y;
        scanf( "%d%d", &x,&y);
        if (x > y) swap(x,y);
        a[x].pb(y-x);
        a[y].pb(x-y+n);
    }
    for (int i = 1; i <= n; ++i) sort(a[i].begin(), a[i].end());
    p[1] = 0;
    int j = 0;
    for (int i = 2; i <= n; ++i) {
        while (j > 0 && !same(a[j+1],a[i])) j = p[j];
        if (same(a[j+1],a[i])) j++;
        p[i] = j;
    }
    if (p[n] * 2 >= n) puts("Yes");
    else puts("No");
}