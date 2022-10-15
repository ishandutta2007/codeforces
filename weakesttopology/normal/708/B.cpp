#include <bits/stdc++.h>
void fail() {
    std::cout << "Impossible\n";
    exit(0);
}
int64_t C2(int64_t N) {
    return N * (N - 1) / 2;
}
int64_t get(int64_t M) {
    int64_t N = 1;
    while (C2(N) < M) {
        ++N;
    }
    if (C2(N) != M) {
        fail();
    }
    return N;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t a[2][2], tot = 0;
    for (int s : {0, 1}) {
        for (int t : {0, 1}) {
            std::cin >> a[s][t];
            tot += a[s][t];
        }
    }
    int64_t cnt[2]{};
    if (a[0][1] == 0 && a[1][0] == 0) {
        if (a[0][0] && a[1][1]) {
            fail();
        } else if (a[0][0]) {
            cnt[0] = get(a[0][0]);
        } else if (a[1][1]) {
            cnt[1] = get(a[1][1]);
        } else {
            std::cout << "1\n";
            exit(0);
        }
    } else {
        for (int b : {0, 1}) {
            cnt[b] = get(a[b][b]);
        }
    }
    if (a[0][1] + a[1][0] != cnt[0] * cnt[1]) {
        fail();
    }
    std::vector<int> s;
    for (int64_t x = cnt[0]; x >= 1; --x) {
        while (x <= a[0][1]) {
            s.push_back(1);
            --cnt[1];
            a[0][1] -= x;
        }
        s.push_back(0);
    }
    for (int i = 0; i < cnt[1]; ++i) {
        s.push_back(1);
    }
    std::reverse(s.begin(), s.end());
    for (int b : s) {
        std::cout << b;
    }
    std::cout << '\n';
    exit(0);
}