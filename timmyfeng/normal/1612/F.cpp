#include <bits/stdc++.h>
using namespace std;

// let u be the maximum level of all armor and v be the maximum level of all weapons.


// let suffix_cost(v) where 1 <= v <= m be the hours required to win given that u = n.


// proposition: let i be the greatest integer such that F_i < n and F_i < m.
// then there must be a solution where u = n or v = m in i hours.

// proof: assume wlog that n < m.

// as soon as u + v + [there is a synergy between (u, v)] >= n,
// the next move can always be (u, v) -> (n, v) because:
// 1) one move must be used regardless to have u = n (u is still less than n)
// 2) any other optimal sequence without this move can still be achieved
//    as previous u are still accessible

// wihtout relying on synergies, (F_i-1, F_i) can be achieved within i - 1 hours,
// (n, F_i) in i hours, and (n, F_i + n) in i + 1 hours. since F_i + n > v,
// the configuration (n, v) must be achieved in i or less hours, completing the proof.


// let weapon(i, u) be the maximum v after i hours given u. if not possible, weapon = 0.
// weapon(i, u) can be calculated only for i up to i_max and 1 <= u <= n.
// the answer is the maximum of i + suffix_cost(weapon(i, n)) over all i.

const int L = 32, N = 200001;

int weapon[L][N], cost[N];
set<int> synergies[N];

void set_max(int &a, int b) {
    if (b > a) {
        a = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    bool flip = n > m;
    if (flip) {
        swap(n, m);
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        if (flip) {
            swap(a, b);
        }

        synergies[a].insert(b);
    }

    int ans = INT_MAX;
    weapon[0][1] = 1;

    for (int i = 0; i < L - 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (weapon[i][j] > 0) {
                int power = j + weapon[i][j] + synergies[j].count(weapon[i][j]);
                set_max(weapon[i + 1][min(n, power)], weapon[i][j]);
                set_max(weapon[i + 1][j], min(m, power));
            }
        }
    }

    for (int i = m - 1; i >= 1; --i) {
        cost[i] = 1 + cost[min(m, n + i + (int) synergies[n].count(i))];
    }

    for (int i = 0; i < L; ++i) {
        if (weapon[i][n] > 0) {
            ans = min(ans, i + cost[weapon[i][n]]);
        }
    }

    cout << ans << "\n";
}