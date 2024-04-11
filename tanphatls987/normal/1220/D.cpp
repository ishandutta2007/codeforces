#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n;
ll a[N];
set<ll> ans;
set<ll> cur;

void solve() {
    vector<ll> use(a + 1, a + n + 1);
    ll mul = 1;
    while (use.size()) {
        cur.clear();
        for(int i = use.size() - 1; i >= 0; i--) {
            if (use[i] % 2) {
                cur.insert(use[i] * mul);
                swap(use[i], use.back());
                use.pop_back();
            } else use[i] /= 2;
        }
        mul *= 2;
        if (cur.size() > ans.size())
            ans = cur;
    }
    cout << n - ans.size() << '\n';
    for(int i = 1; i <= n; i++) if (!ans.count(a[i]))
        cout << a[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    solve();

}