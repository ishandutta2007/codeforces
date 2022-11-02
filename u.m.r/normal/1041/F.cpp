#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;

ll a[MAXN], b[MAXN];
int n, m, Y1, Y2;

int gao(int o) {
    unordered_map<int, int> mp;
    int s1 = 1 << o;
    int s2 = s1 * 2;
    for (int i = 1; i <= n; i++) {
        mp[(a[i] + s1) % s2]++;
    }
    for (int i = 1; i <= m; i++) {
        mp[b[i] % s2]++;
    }
    int ret = 0;
    for (auto &x : mp) ret = max(ret, x.second);
    return ret;
}

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d%d", &n, &Y1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    scanf("%d%d", &m, &Y2);
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if (a[i] & 1) ans++;
    for (int i = 1; i <= m; i++)
        if (!(b[i] & 1)) ans++;
    ans = max(ans, n + m - ans);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[a[i]]++;
    for (int j = 1; j <= m; j++) mp[b[j]]++;
    for (auto &x : mp) ans = max(ans, x.second);
    for (int o = 1; o < 30; o++) {
        ans = max(gao(o), ans);
    }
    printf("%d\n", ans);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}