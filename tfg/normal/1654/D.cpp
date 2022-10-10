#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int MOD = 998244353;

template <class T>
T fexp(T x, long long e) {
    T ans(1);
    for(; e > 0; e /= 2) {
        if(e & 1) ans = ans * x;
        x = x * x;
    }
    return ans;
}

template <int mod = MOD>
struct modBase {
    modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
    int val;
 
    void operator += (modBase<mod> o) { *this = *this + o; }
    void operator -= (modBase<mod> o) { *this = *this - o; }
    void operator *= (modBase<mod> o) { *this = *this * o; }
    //void operator /= (modBase<mod> o) { *this = *this / o; }
    modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
    modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
    modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
    modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

    friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
        return os << p.val;
    }
    friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
        return is >> p.val;
    }
};

std::vector<int> fat[ms];

struct Edge {
    int to;
    int x, y;
};

int f[ms], g[ms];
std::vector<int> used;
std::vector<Edge> edges[ms];

void useEdge(int val, int delta) {
    for(auto x : fat[val]) {
        //std::cout << x << " * " << delta << '\n';
        f[x] += delta;
        if(f[x] == -1) {
            //std::cout << "adding " << x << '\n';
            f[x] = 0;
            g[x]++;
            used.push_back(x);
        } else if(g[x] < f[x] && 0) {
            g[x]++;
            //std::cout << "adding " << x << '\n';
            used.push_back(x);
        }
    }
}

modBase<> dfs(int on, int par, modBase<> val) {
    //std::cout << "at " << on << " with " << val << '\n';
    modBase<> ans = val;
    for(auto [to, x, y] : edges[on]) if(to != par) {
        useEdge(x, 1);
        useEdge(y, -1);
        ans += dfs(to, on, val * x / y);
        useEdge(y, 1);
        useEdge(x, -1);
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    for(int i = 2; i < ms; i++) if(fat[i].empty()) {
        for(int j = i; j < ms; j += i) {
            int x = j;
            while(x % i == 0) x /= i, fat[j].push_back(i);
        }
    }
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        for(int i = 1; i < n; i++) {
            int u, v, x, y;
            std::cin >> u >> v >> x >> y;
            u--;v--;
            edges[u].push_back({v, y, x});
            edges[v].push_back({u, x, y});
        }
        auto ans = dfs(0, 0, modBase<>(1));
        for(auto x : used) {
            ans *= x;
            f[x] = g[x] = 0;
        }
        used.clear();
        for(int i = 0; i < n; i++) edges[i].clear();
        std::cout << ans << '\n';
    }
}