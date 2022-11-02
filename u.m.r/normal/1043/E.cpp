#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n, m;

struct pt{
    int x, y, z, num;
} a[MAXN];

ll s1[MAXN], s2[MAXN];
ll ans[MAXN];

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].z = a[i].x - a[i].y;
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, [](const pt & a, const pt & b){
        return a.z < b.z;
    });
    for (int i = 1; i <= n; i++){
        s1[i] = s1[i - 1] + a[i].x;
    }
    for (int i = n; i >= 1; i--)
        s2[i] = s2[i + 1] + a[i].y;
    for (int i = 1; i <= n; i++){
        ll ret = 0;
        ret += s1[i - 1] + s2[i + 1] + (i - 1) * 1ll * a[i].y + (n - i) * 1ll * a[i].x;
        ans[a[i].num] = ret;
    }
    sort(a + 1, a + n + 1, [](const pt & a, const pt & b){
        return a.num < b.num;
    });
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        ll ret = min(a[x].x + a[y].y, a[x].y + a[y].x);
        ans[x] -= ret;
        ans[y] -= ret;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld%c", ans[i], " \n"[i == n]);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}