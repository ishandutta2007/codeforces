#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>
#include <complex>
#include <bitset>
#include <iomanip>

#define rep(i, n, s) for (int i = (s); i < int(n); i++)
#define per(i, n, s) for (int i = (n - 1); i >= int(s); i--)
#define MM << " " <<
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using MaxHeap = std::priority_queue<T>;

using ll = long long;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Pdd = std::pair<double, double>;

template <class T>
bool chmin(T &a, const T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool chmax(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
void vdeb(const std::vector<T> &da) {
    auto n = da.size();
    for (size_t i = 0; i < n; i++) {
        if (i == n - 1)
            std::cout << da[i] << std::endl;
        else
            std::cout << da[i] << " ";
    }
}
template<class T>
void vdeb(const std::vector<std::vector<T>> &da) {
    auto n = da.size();
    for (size_t i = 0; i < n; i++) {
        std::cout << i << " : ";
        vdeb(da[i]);
    }
}

template <>
void vdeb(const std::vector<std::string> &da) {
    auto n = da.size();
    for (size_t i = 0; i < n; i++) { std::cout << da[i] << std::endl; }
}

using namespace std;

using Real = double;
using Point = pair<Real, Real>;
constexpr Real EPS = 1e-10;
const Real Pi = std::acos(Real(-1.0));
const Real Tau = Pi*2;

int main() {
    int n, k; cin >> n >> k;
    vector<Point> da(n);
    rep(i,n,0) cin >> da[i].first >> da[i].second;
    vector<Real> args(n), dist(n);
    rep(i,n,0) {
        args[i] = atan2(da[i].second, da[i].first);
        dist[i] = hypot(da[i].second, da[i].first);
    }
    vector<pair<Real, int>> event(n*4);
    Real ok = 1e6, ng = 0.0;
    rep(times, 40, 0) {
        auto now = (ok + ng) / 2;
        rep(i,n,0) {
            if(dist[i] > now) {
                event[i*4    ] = {0, 0};
                event[i*4 + 1] = {0, 0};
                event[i*4 + 2] = {0, 0};
                event[i*4 + 3] = {0, 0};
            } else {
                auto tmp = acos(dist[i] / now);
                event[i*4    ] = {args[i] - tmp, 1};
                event[i*4 + 1] = {args[i] + tmp, -1};
                event[i*4 + 2] = {args[i] - tmp + Tau, 1};
                event[i*4 + 3] = {args[i] + tmp + Tau, -1};
            }
        }
        sort(all(event));
        int cnt = 0;
        bool flg = false;
        for(auto &i : event) {
            cnt += i.second;
            if(cnt >= k) {
                flg = true;
                break;
            }
        }
        if(flg) {
            ok = now;
        } else {
            ng = now;
        }
    }
    cout << setprecision(10) << endl;
    cout << ok / 2 << endl;
}