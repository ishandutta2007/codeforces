#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::unordered_map<unsigned long long, int> f;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    f.reserve(1 << 22);
    f.max_load_factor(0.25);
    int n, m;
    std::cin >> n >> m;
    std::map<int, unsigned long long> h;
    std::uniform_int_distribution<unsigned long long> dist;
    auto getHash = [&](int x) {
        if(!h.count(x)) {
            h[x] = dist(rng);
        }
        return h[x];
    };
    struct Info {
        std::vector<unsigned long long> values;
        int w;

        bool operator < (const Info &o) const { return w < o.w; }
    };
    std::vector<Info> a(n);
    for(int i = 0; i < n; i++) {
        std::vector<unsigned long long> kek;
        for(int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            kek.push_back(getHash(x));
        }
        a[i].values = kek;
        std::cin >> a[i].w;
    }
    std::sort(a.begin(), a.end());
    const long long INF = 1e18;
    long long ans = INF;
    int pref = n;
    for(auto info : a) {
        for(int i = 0; i < (1 << m); i++) {
            unsigned long long cur = 0;
            for(int j = 0; j < m; j++) if((1 << j) & i) cur ^= info.values[j];
            f[cur]++;
        }
    }
    for(auto info : a) {
        int got = 0;
        for(int i = 0; i < (1 << m); i++) {
            unsigned long long cur = 0;
            int sign = 1;
            for(int j = 0; j < m; j++) if((1 << j) & i) cur ^= info.values[j], sign = -sign;
            got += sign * f[cur];
        }
        if(got) {
            while(got > 0 && pref > 0) {
                auto info2 = a[--pref];
                for(int i = 0; i < (1 << m); i++) {
                    unsigned long long cur = 0;
                    for(int j = 0; j < m; j++) if((1 << j) & i) cur ^= info2.values[j];
                    f[cur]--;
                }
                bool isGood = true;
                for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) {
                    if(info.values[i] == info2.values[j]) isGood = false;
                }
                if(isGood) {
                    got--;
                }
            }
            assert(pref >= 0);
            ans = std::min(ans, (long long) info.w + a[pref].w);
        }
    }
    if(ans == INF) ans = -1;
    std::cout << ans << '\n';
}