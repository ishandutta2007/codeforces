#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;
const int MOD = 998244353;

typedef long long ll;


int n, m;
int a[N];
int way[N];
int bonus[N];
map<int, int> ma[N];

void modified(ll &res, int pos, int type) {
    res -= way[pos];
    bonus[pos] += type;

    way[pos] = max(0, a[pos] - bonus[pos]);
    res += way[pos];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) way[i] = a[i];

    long long res = 0;
    for(int i = 1; i <= n; i++) res += a[i];

    cin >> m;
    while (m--) {
        int s, t, u;
        cin >> s >> t >> u;
        if (ma[s][t] != 0) { 
            modified(res, ma[s][t], -1);
        }
        ma[s][t] = u;
        if (ma[s][t] != 0) 
            modified(res, ma[s][t], 1);
        cout << res << '\n';
    }
}