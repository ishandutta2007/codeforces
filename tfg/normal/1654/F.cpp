#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::string str;
    std::cin >> n >> str;
    int sz = 1 << n;
    std::vector<int> ord(sz), perm(sz);
    for(int i = 0; i < sz; i++) {
        ord[i] = str[i] - 'a';
        perm[i] = i;
    }
    std::vector<std::pair<int, int>> temp(sz);
    for(int rep = 0; rep < n; rep++) {
        for(int i = 0; i < sz; i++) {
            temp[i] = {ord[i], ord[i^(1<<rep)]};
        }
        std::sort(perm.begin(), perm.end(), [&](int v1, int v2) { return temp[v1] < temp[v2]; });
        int val = 0;
        for(int l = 0, r = 0; l < sz; l = r, val++) {
            while(r < sz && temp[perm[l]] == temp[perm[r]]) {
                ord[perm[r++]] = val;
            }
        }
    }
    int best = 0;
    for(int i = 0; i < sz; i++) {
        if(ord[best] > ord[i]) {
            best = i;
        }
    }
    for(int i = 0; i < sz; i++) {
        std::cout << str[i ^ best];
    }
    std::cout << '\n';
}