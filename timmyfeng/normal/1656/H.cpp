#include <bits/stdc++.h>
using namespace std;

__int128 to_int128(string s) {
    __int128 result = 0;
    for (auto c : s) {
        result = result * 10 + c - '0';
    }
    return result;
}

string to_string(__int128 x) {
    string result;
    while (x) {
        result += (char) (x % 10 + '0');
        x /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

__int128 gcd(__int128 a, __int128 b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<map<__int128, int>> prime_factors(n + m);
        vector<__int128> nums(n + m);
        set<__int128> primes;

        for (int i = 0; i < n + m; ++i) {
            string x; cin >> x;
            nums[i] = to_int128(x);
            ++prime_factors[i][nums[i]];
            primes.insert(nums[i]);
        }

        while (!primes.empty()) {
            __int128 x = *--primes.end();
            primes.erase(--primes.end());

            for (auto y : primes) {
                __int128 g = gcd(x, y);
                if (g == 1) continue;

                for (auto z : {x, y}) {
                    if (g == z) continue;

                    primes.insert(z / g);

                    for (int i = 0; i < n + m; ++i) {
                        if (prime_factors[i].count(z)) {
                            prime_factors[i][g] += prime_factors[i][z];
                            prime_factors[i][z / g] += prime_factors[i][z];
                            prime_factors[i].erase(z);
                        }
                    }
                }

                primes.erase(y);
                primes.insert(g);
                break;
            }
        }

        vector factors(n + m, vector<__int128>());
        map<__int128, set<int>> multiples;
        queue<__int128> to_erase;

        for (int i = 0; i < n + m; ++i) {
            for (auto [p, a] : prime_factors[i]) {
                __int128 f = 1;
                while (a--) {
                    f *= p;
                    factors[i].push_back(f);
                    multiples[f].insert(i);
                }
            }
        }

        for (auto &[f, ids] : multiples) {
            if (*ids.begin() >= n || *--ids.end() < n)
                to_erase.push(f);
        }

        vector<bool> in_answer(n + m, true);
        set<__int128> erased;

        while (!to_erase.empty()) {
            __int128 f = to_erase.front(); to_erase.pop();

            set<int> bad_nums = multiples[f];
            for (auto i : bad_nums) {
                in_answer[i] = false;
                for (auto g : factors[i]) {
                    multiples[g].erase(i);
                    if (!erased.count(g)) {
                        if (multiples[g].empty() || *multiples[g].begin() >= n || *--multiples[g].end() < n) {
                            erased.insert(g);
                            to_erase.push(g);
                        }
                    }
                }
            }
        }

        if (!count(in_answer.begin(), in_answer.end(), true)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << count(in_answer.begin(), in_answer.begin() + n, true) << " " <<
                    count(in_answer.begin() + n, in_answer.end(), true) << "\n";

            for (int i = 0; i < n; ++i) {
                if (in_answer[i]) cout << to_string(nums[i]) << " ";
            }
            cout << "\n";

            for (int i = n; i < n + m; ++i) {
                if (in_answer[i]) cout << to_string(nums[i]) << " ";
            }
            cout << "\n";
        }
    }
}