#include <bits/stdc++.h>
using namespace std;

vector<array<int, 4>> solve(int n, vector<array<int, 2>> diagonals) {
    for (auto &[a, b] : diagonals) {
        --a, --b;
    }

    vector<int> mapping(n);
    iota(mapping.begin(), mapping.end(), 1);

    vector<array<int, 4>> ans;

    while (!diagonals.empty()) {
        int vertex = -1;
        for (auto it = diagonals.begin(); it != diagonals.end(); ++it) {
            auto [a, b] = *it;
            if ((b - a + n) % n == 2 || (a - b + n) % n == 2) {
                int c = (b - a + n) % n == 2 ? (a + 1) % n : (b + 1) % n;
                if (c == 0) {
                    if (n == 4) {
                        c = 2;
                    } else {
                        continue;
                    }
                }

                if (c > 1 && c < n - 1) {
                    ans.push_back({mapping[0], mapping[c], mapping[a], mapping[b]});
                }

                diagonals.erase(it);
                vertex = c;
                break;
            }
        }

        mapping.erase(mapping.begin() + vertex);
        for (auto &[a, b] : diagonals) {
            a -= a > vertex;
            b -= b > vertex;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 2>> initial(n - 3), goal(n - 3);
    for (auto &[a, b] : initial) {
        cin >> a >> b;
    }
    for (auto &[a, b] : goal) {
        cin >> a >> b;
    }

    vector<array<int, 4>> to = solve(n, initial);
    vector<array<int, 4>> from = solve(n, goal);
    reverse(to.begin(), to.end());

    cout << to.size() + from.size() << "\n";
    for (auto [a, b, c, d] : to) {
        cout << c << " " << d << "\n";
    }
    for (auto [a, b, c, d] : from) {
        cout << a << " " << b << "\n";
    }
}