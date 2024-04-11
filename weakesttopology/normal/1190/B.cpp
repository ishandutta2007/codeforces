#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int eq = 0;
    for (int i = 0; i + 1 < N; ++i) {
        eq += a[i] == a[i + 1];
    }
    int64_t sum = 0;
    bool stuck = false;
    for (int i = 0; i < N; ++i) {
        if (a[i] < i) {
            stuck = true;
            break;
        }
        sum += a[i] - i;
    }
    for (int i = 0; i + 2 < N; ++i) {
        if (a[i + 1] <= a[i] + 1 && a[i + 1] == a[i + 2]) {
            stuck = true;
        }
    }
    std::cout << (eq > 1 || stuck || sum % 2 == 0 ? "cslnb" : "sjfnb") << '\n';
    exit(0);
}