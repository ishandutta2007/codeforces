#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n, m;
priority_queue<PLI> q;
int a[MAXN], b[MAXN];

inline ll gao(int l, int k) {
    int p = l / k;
    int a = l - k * p; // p + 1;
    int b = k - a;
    return 1ll * a * (p + 1) * (p + 1) + 1ll * b * p * p;
}

ll calc(int l, int k) {
    if (k == l) return 0;
    else return gao(l, k) - gao(l, k + 1);
}

void solve(int casi){
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = 1;
        q.push(PLI(calc(a[i], b[i]), i));
        ans += 1ll * a[i] * a[i];
    }
    for (int i = 1; i <= m - n; i++) {
        auto p = q.top();
        q.pop();
        ans -= p.first;
        int x = p.second;
        b[x]++;
        q.push(PLI(calc(a[x], b[x]), x));
    }
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}