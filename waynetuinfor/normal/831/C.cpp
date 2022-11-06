#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2000 + 10;
int a[maxn], b[maxn], s[maxn], n, k;
set<int> ans;

bool check(int);

main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int s = 0;
    for (int i = 0; i < k; ++i) {
        s += a[i];
        if (check(b[0] - s)) ans.insert(b[0] - s);
    }
    cout << ans.size() << endl;
    return 0;
}

bool check(int init) {
    set<int> chk;
    for (int i = 0; i < n; ++i) chk.insert(b[i]);
    int ind = 0;
    for (int i = 0; i < k; ++i) {
        init += a[i];
        if (chk.count(init)) chk.erase(init);
    }
    return chk.size() == 0;
}