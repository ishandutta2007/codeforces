#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, cnt;
int a[N], fa[N], nxt[N];

int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", a + i);
        rep(i, 1, n - 1) nxt[i] = i + 1;
        nxt[n] = 1;
        cnt = 0;

        rep(i, 1, n) if (__gcd(a[i], a[nxt[i]]) == 1)
            cnt++,
            fa[i] = i;
        else fa[i] = nxt[i];

        if (cnt == 0) {
            printf("0\n");
            continue;
        }

        int idx = 1;
        vector<int> ans;
        while (cnt) {
            idx = find(idx);
            int idx1 = nxt[idx], idx2 = nxt[idx1];
            //cerr << idx << " " << idx1 << " " << idx2 << endl;
            ans.PB(idx1);
            cnt = cnt - 1 - (__gcd(a[idx1], a[idx2]) == 1) + (__gcd(a[idx], a[idx2]) == 1);
            nxt[idx] = idx2;
            fa[idx] = __gcd(a[idx], a[idx2]) == 1 ? idx : idx2;
            idx = nxt[idx];
        }
        //cerr << endl;
        printf("%d ", ans.size());
        for (auto x : ans)
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}