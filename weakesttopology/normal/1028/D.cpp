#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    constexpr ll mod = 1e9 + 7;

    set<int> init, buy, sell;
    buy.insert(-INF), sell.insert(+INF);

    ll ans = 1;

    for (int i = 0; i < n; ++i) {
        string type;
        cin >> type;
        int p;
        cin >> p;

        if (type == "ADD") {
            if (p < *rbegin(buy)) buy.insert(p);
            else if (p > *begin(sell)) sell.insert(p);
            else init.insert(p);
        }
        else {
            if (init.count(p)) {
                ans = (2 * ans) % mod;
                auto iter = init.erase(init.find(p));
                while (iter != end(init)) {
                    sell.insert(*iter);
                    iter = init.erase(iter);
                }
                buy.merge(init);
            }
            else if (p == *rbegin(buy)) {
                sell.merge(init);
                buy.erase(prev(end(buy)));
            }
            else if (p == *begin(sell)) {
                buy.merge(init);
                sell.erase(begin(sell));
            }
            else {
                ans = 0;
                break;
            }
            assert(empty(init));
        }
    }

    ans = (ans * (size(init) + 1)) % mod;

    cout << ans << endl;

    exit(0);
}