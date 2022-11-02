#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

template <class Type>
class BIT {
public:
    explicit BIT(int length) : length(length) {
        data.assign(length + 1, 0);
    }

    Type query(int index) const {
        ++index;
        Type sum = 0;
        while (index > 0) {
            sum += data[index];
            index -= (index & -index);
        }
        return sum;
    }

    void update(int index, Type diff) {
        ++index;
        while (index <= length) {
            data[index] += diff;
            index += (index & -index);
        }
    }

    int length;
    std::vector<Type> data;
};

const int V = 300000;

vector<int> path[V];
vector<pair<int, ll>> query[V];
int depth[V];
ll ans[V];
BIT<ll> bit(V + 1);

void dfs(int v, int d) {
    depth[v] = d;

    for (auto p : query[v]) {
        int l;
        ll x;
        tie(l, x) = p;
        bit.update(depth[v], x);
        bit.update(min(depth[v] + l + 1, V), -x);
    }

    ans[v] = bit.query(depth[v]);

    for (int sv : path[v]) {
        if (depth[sv] < 0) dfs(sv, d + 1);
    }

    for (auto p : query[v]) {
        int l;
        ll x;
        tie(l, x) = p;
        bit.update(depth[v], -x);
        bit.update(min(depth[v] + l + 1, V), x);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int v, l;
        ll x;
        cin >> v >> l >> x;
        --v;
        query[v].push_back(make_pair(l, x));
    }

    fill(depth, depth + N, -1);
    dfs(0, 0);

    for (int v = 0; v < N; ++v) {
        cout << ans[v] << " ";
    }
    cout << endl;
    return 0;
}