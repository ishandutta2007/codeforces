#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int MOD = 998244353;
int n, k, a[MAXN], pos[MAXN];

int main() {    
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    long long sum = 0;
    
    vector<int> p;
    for(int x = n - k + 1; x <= n; ++x) {
        p.push_back(pos[x]);
        sum += x;
    }

    sort(p.begin(), p.end());

    int cnt = 1;
    for(int i = 1; i < k; ++i) {
        cnt = (1LL * cnt * (p[i] - p[i-1])) % MOD;
    }

    printf("%lld %d\n", sum, cnt);


    return 0;
}