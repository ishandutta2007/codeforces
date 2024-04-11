#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

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

int main() {
    int N;
    ll t;
    cin >> N >> t;

    auto sum = Vec<ll>(N + 1, 0LL);
    for (int i = 1; i <= N; ++i) {
        ll a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }

    vector<ll> val;
    for (ll v : sum) {
        val.push_back(v);
        val.push_back(v + t - 1);
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    int M = val.size();

    map<ll, int> rev;
    for (int i = 0; i < M; ++i) rev[val[i]] = i;

    ll ans = 0;
    BIT<ll> bit(M);
    for (int i = N; i >= 0; --i) {
        ans += bit.query(rev[sum[i] + t - 1]);
        bit.update(rev[sum[i]], 1);
    }

    cout << ans << endl;
    return 0;
}