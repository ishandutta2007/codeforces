#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1000;

int C = 1;
bool shelf[100010][ms];
int cnt[100010];
int state[100010][ms];

int n, m, q;

int copyShelf(int id) {
    assert(C < 100010);
    for(int i = 0; i < m; i++) {
        shelf[C][i] = shelf[id][i];
    }
    cnt[C] = cnt[id];
    return C++;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::cin >> n >> m >> q;
    for(int i = 1; i <= q; i++) {
        int t;
        std::cin >> t;
        for(int j = 0; j < n; j++) {
            state[i][j] = state[i-1][j];
        }
        if(t == 1 || t == 2) {
            int x, y;
            std::cin >> x >> y;
            x--;y--;
            int pos = copyShelf(state[i][x]);
            cnt[pos] -= shelf[pos][y] ? 1 : 0;
            shelf[pos][y] = t == 1;
            cnt[pos] += shelf[pos][y] ? 1 : 0;
            state[i][x] = pos;
        } else if(t == 3) {
            int x;
            std::cin >> x;
            x--;
            int pos = copyShelf(state[i][x]);
            cnt[pos] = m - cnt[pos];
            for(int j = 0; j < m; j++) {
                shelf[pos][j] = !shelf[pos][j];
            }
            state[i][x] = pos;
        } else {
            int x;
            std::cin >> x;
            for(int j = 0; j < n; j++) {
                state[i][j] = state[x][j];
            }
        }
        int ans = 0;
        for(int j = 0; j < n; j++) {
            ans += cnt[state[i][j]];
        }
        std::cout << ans << '\n';
    }
}