#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Group {
    char ch;
    std::vector<long long> vals, suf;
    void prep() {
        std::sort(vals.begin(), vals.end());
        suf.assign(vals.size() + 1, 0);
        for(int i = (int) vals.size() - 1; i >= 0; i--) {
            suf[i] = vals[i] + suf[i+1];
            sum += vals[i];
        }
    }

    std::pair<int, long long> search(long long x) {
        if(coef == 0) {
            return {0, 0};
        }
        int id = (int)(std::lower_bound(vals.begin(), vals.end(), (x + coef - 1) / coef) - vals.begin());
        return {(int) vals.size() - id, suf[id] * coef};
    }
    long long sum = 0;
    long long coef;
};

std::vector<Group> groups;
std::vector<int> mults;
std::vector<std::vector<int>> ids;
std::vector<bool> got;

int p, m;

int getId(int x) {
    int id = 0;
    while(id < (int) mults.size() && mults[id] != x) id++;
    if(id == (int) mults.size()) {
        mults.push_back(x);
        ids.push_back(std::vector<int>());
    }
    assert(id < (int) mults.size() && id < (int) ids.size());
    return id;
}

long long ans = 0, totMul = 1;

void gen(int on, int b) {
    if(on == (int) mults.size()) {
        long long curMul = totMul;
        int canUse = b / p;
        long long baseAns = totMul;
        for(int i = 0; i < (int) groups.size(); i++) {
            if(groups[i].ch == '*') {
                if(!got[i]) {
                    curMul /= groups[i].sum;
                }
            } else {
                baseAns += groups[i].sum * curMul;
                groups[i].coef = totMul - curMul;
            }
        }
        long long l = 0, r = 1e18;
        auto search = [&](long long x) {
            std::pair<int, long long> gg(0, 0);
            for(int i = 0; i < (int) groups.size(); i++) if(groups[i].ch == '+') {
                auto [xx, y] = groups[i].search(x);
                gg.first += xx, gg.second += y;
            }
            return gg;
        };
        while(l != r) {
            long long mid = (l + r + 1) / 2;
            if(search(mid).first >= canUse) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        auto [x, y] = search(l);
        ans = std::max(ans, baseAns + y - std::max(0, x - canUse) * l);
    } else {
        gen(on+1, b);
        for(int i = 0; i < (int) ids[on].size() && b >= m; i++) {
            b -= m;
            got[ids[on][i]] = true;
            gen(on+1, b);
        }
        for(int i = 0; i < (int) ids[on].size(); i++) {
            got[ids[on][i]] = false;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, b;
    std::cin >> n >> b >> p >> m;
    std::vector<std::pair<char, int>> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    for(int l = 0, r = 0; l < n; l = r) {
        if(a[l].first == '*' && a[l].second == 1) {
            r++;
            continue;
        }
        groups.push_back(Group());
        auto &cur = groups.back();
        cur.ch = a[l].first;
        cur.vals.push_back(a[r++].second);
        while(a[l].first == '+' && r < n && a[r].first == '+') {
            cur.vals.push_back(a[r++].second);
        }
        if(a[l].first == '*') {
            ids[getId(a[l].second)].push_back((int) groups.size() - 1);
            totMul *= a[l].second;
        }
        cur.prep();
    }
    got.assign(groups.size(), false);
    gen(0, b);
    std::cout << ans << '\n';
}