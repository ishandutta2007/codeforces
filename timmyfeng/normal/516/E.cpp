#include <bits/stdc++.h>
using namespace std;

array<long long, 2> euclid(long long a, long long b) {
    if (b == 0) {
        return {1, 0};
    } else {
        auto [x, y] = euclid(b, a % b);
        return {y, x - (a / b) * y};
    }
}

long long solve(long long n, long long m, vector<long long> x, vector<long long> y) {
    if (x.empty() && y.empty()) {
        cout << -1 << "\n";
        exit(0);
    }

    long long ans = -1;
    for (int k = 0; k < 2; ++k) {
        long long inv = (euclid(m, n)[0] % n + n) % n;
        sort(x.begin(), x.end());

        vector<long long> happy;
        happy.insert(happy.end(), x.begin(), x.end());
        happy.insert(happy.end(), y.begin(), y.end());

        sort(happy.begin(), happy.end(), [&](long long a, long long b) {
            if (a * inv % n == b * inv % n) {
                return a < b;
            } else {
                return a * inv % n < b * inv % n;
            }
        });
        happy.erase(unique(happy.begin(), happy.end()), happy.end());

        rotate(happy.begin(), min_element(happy.begin(), happy.end()), happy.end());

        int i = 0;
        do {
            long long diff = 0;
            int j = (i + 1) % happy.size();
            while (true) {
                diff = ((happy[j] - happy[i]) * inv % n + n) % n * m;
                if (happy[i] + diff >= happy[j]) {
                    break;
                }
                j = (j + 1) % happy.size();
            }

            if (diff == 0) {
                diff = n * m;
            }

            if (diff > m || !binary_search(x.begin(), x.end(), happy[i])) {
                ans = max(ans, happy[i] + diff - m);
            }

            i = j;
        } while (i != 0);

        swap(n, m), swap(x, y);
    }

    return ans;
}

void read(map<long long, vector<long long>> &x, long long g) {
    int n;
    cin >> n;

    while (n--) {
        long long a;
        cin >> a;
        x[a % g].push_back(a / g);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    long long g = __gcd(n, m);

    map<long long, vector<long long>> x, y;
    read(x, g), read(y, g);

    long long ans = 0;
    for (int i = 0; i < g; ++i) {
        ans = max(ans, g * solve(n / g, m / g, x[i], y[i]) + i);
    }

    cout << ans << "\n";
}