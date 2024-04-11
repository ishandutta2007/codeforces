#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

bool cmp (psi a, psi b) {
    return a.yy > b.yy;
}

vector <psi> g[11001];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, x;
    cin >> n >> m;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &x);
        mp[x] = 1;
    }
    int sum = 0;
    vector <int> res;
    for (int i = 1; ; i++) {
        if (mp[i]) continue;
        sum += i;
        if (sum > m) break;
        res.push_back (i);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) printf ("%d ", res[i]);
}